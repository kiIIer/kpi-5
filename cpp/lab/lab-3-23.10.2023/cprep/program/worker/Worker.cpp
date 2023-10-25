//
// Created by Michael Molchanov on 24.10.2023.
//

#include "Worker.h"

void Worker::work(IQueue<RegexTask> *taskQueue, IQueue<RegexResult> *resultQueue, UserOptions *options) {
    // Compile all the patterns once to reuse
    std::vector<std::regex> compiledPatterns;
    for (const auto &pattern: options->patterns) {
        std::regex::flag_type flags = std::regex::ECMAScript;
        if (options->ignoreCase) {
            flags |= std::regex::icase;
        }
        compiledPatterns.emplace_back(pattern, flags);
    }

    while (true) {
        RegexTask task;
        if (!taskQueue->pop(task)) {
            return;
        }

        // Terminate if lineNumber is -1
        if (task.lineNumber == -1) {
            return;
        }

        bool isMatch = matchesPattern(*task.lineText, compiledPatterns);

        if (isMatch ^ options->invertMatch) {
            RegexResult result;
            result.lineNumber = task.lineNumber;
            result.matchedText = task.lineText;
            resultQueue->push(result);
        } else {
            // Cleanup if the line doesn't match and isn't used
            delete task.lineText;
        }
    }
}

bool Worker::matchesPattern(const std::string &line, const std::vector<std::regex> &compiledPatterns) {
    for (const auto &pattern: compiledPatterns) {
        if (std::regex_search(line, pattern)) {
            return true;
        }
    }
    return false;
}


Worker::Worker() {

}
