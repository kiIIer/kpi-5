//
// Created by Michael Molchanov on 24.10.2023.
//

#include <fstream>
#include <iostream>
#include "Program.h"

Program::Program(IOptionParser *optionParser, IWorker *worker, IResultExporter *exporter, IQueueFactory *queueFactory)
        : optionParser(optionParser), worker(worker), exporter(exporter), taskQueue(queueFactory->createTask()),
          resultQueue(queueFactory->createResult()) {}

int Program::run(int argc, char **argv) {
    CLI::App app("Cpp Parallel Global Regular Expression Print");
    std::unique_ptr<UserOptions> userOptions = optionParser->parse(app);


    app.callback([&]() {
        static std::ofstream log_stream(userOptions->log_file);
        std::cerr.rdbuf(log_stream.rdbuf());
        std::cerr << "Logging to " << userOptions->log_file << std::endl;
        std::cerr << "Spawning threads" << std::endl;
        std::vector<std::thread> workerThreads;

        for (int i = 0; i < userOptions->threads; ++i) {
            workerThreads.emplace_back([this, &userOptions]() {
                worker->work(taskQueue.get(), resultQueue.get(), userOptions.get());
            });
            std::cerr << "Spawned " << i << std::endl;
        }

        std::cerr << "Distributing tasks" << std::endl;
        distributeTasks(userOptions.get());

        std::cerr << "Joining threads" << std::endl;
        for (auto &t: workerThreads) {
            t.join();
        }

        std::cerr << "Gathering results" << std::endl;
        resultQueue->shouldTerminate();
        if (!userOptions->unorderedOut) {
            std::vector<RegexResult> results = gatherResultsFromAllWorkers();

            std::cerr << "Exporting" << std::endl;
            exporter->exportResults(results, userOptions.get());

            std::cerr << "Deleting results" << std::endl;
            for (auto res: results) {
                delete res.matchedText;
            }
        } else {
            RegexResult res;
            while (resultQueue->pop(res)) {
                std::cout << res.matchedText << std::endl;
                delete res.matchedText;
            }
        }

        std::cerr << "Exiting callback" << std::endl << std::flush;
    });


    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    return 0;
}

void Program::distributeTasks(UserOptions *userOptions) {
    std::istream *input = &std::cin;  // Default to stdin
    std::ifstream fileStream;
    if (userOptions->inputFile) {     // If an input file is provided
        fileStream.open(userOptions->inputFile.value());
        input = &fileStream;
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(*input, line)) {
        std::string *heapLine = new std::string(line);
        RegexTask task = {lineNumber++, heapLine, userOptions};
        taskQueue->push(task);
    }

    taskQueue->shouldTerminate();
//    RegexTask terminationTask = {-1, nullptr, nullptr};
//    for (int i = 0; i < userOptions->threads; ++i) {
//        taskQueue->push(terminationTask);
//    }

    if (userOptions->inputFile) {
        fileStream.close();
    }
}

std::vector<RegexResult> Program::gatherResultsFromAllWorkers() {
    std::vector<RegexResult> results;
    RegexResult res;

    std::cerr << "Starting popping" << std::endl;
    while (resultQueue->pop(res)) {
        std::cerr << "Popped" << res.lineNumber << std::endl;
        results.push_back(res);
    }
    std::cerr << "exiting" << std::endl;
    return results;
}