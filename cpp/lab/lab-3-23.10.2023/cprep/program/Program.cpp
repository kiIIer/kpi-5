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
    // Parse options
    Options *userOptions = optionParser->parse(argc, argv);

    // Check and read patterns from a file if provided
    if (!userOptions->patternFile.empty()) {
        readPatternsFromFile(userOptions);
    }

    // Start worker threads
    std::vector<std::thread> workerThreads;
    for (int i = 0; i < userOptions->threads; ++i) {
        workerThreads.emplace_back([this]() {
            worker->work(taskQueue.get(), resultQueue.get());
        });
    }

    // Send tasks
    distributeTasks(userOptions);

    for (auto &t: workerThreads) {
        t.join();
    }

    std::vector<Result> results = gatherResultsFromAllWorkers();
    exporter->exportResults(results);

    delete userOptions;
    for (auto res: results) {
        delete res.matchedText;
    }
}

void Program::distributeTasks(Options *userOptions) {
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
        Task task = {lineNumber++, heapLine, userOptions};
        taskQueue->push(task);
    }

    // Signal workers there's no more work
    Task terminationTask = {-1, nullptr, nullptr};
    for (int i = 0; i < userOptions->threads; ++i) {
        taskQueue->push(terminationTask);
    }

    if (userOptions->inputFile) {
        fileStream.close();
    }
}

void Program::readPatternsFromFile(Options *opts) {
    std::ifstream file(opts->patternFile);
    std::string line;
    while (std::getline(file, line)) {
        opts->patterns.push_back(line);
    }
}

std::vector<Result> Program::gatherResultsFromAllWorkers() {
    std::vector<Result> results;
    Result res;
    while (resultQueue->pop(res)) {
        results.push_back(res);
    }
    return results;
}