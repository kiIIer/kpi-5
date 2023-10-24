//
// Created by Michael Molchanov on 24.10.2023.
//

#include <iostream>
#include "ResultExporter.h"
#include "sstream"

void ResultExporter::exportResults(std::vector<Result> results, Options *options) {
    // Sort the results based on lineNumber
    std::sort(results.begin(), results.end(), [](const Result &a, const Result &b) {
        return a.lineNumber < b.lineNumber;
    });

    for (const Result &result: results) {
        if (options->showLineNumber) {
            std::cout << result.lineNumber << ":";
        }

        std::cout << *(result.matchedText) << std::endl;
    }
}


ResultExporter::ResultExporter() {

}
