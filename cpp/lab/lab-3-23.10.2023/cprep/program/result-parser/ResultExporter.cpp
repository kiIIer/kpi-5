//
// Created by Michael Molchanov on 24.10.2023.
//

#include <iostream>
#include "ResultExporter.h"
#include "sstream"

void ResultExporter::exportResults(std::vector<RegexResult> results, UserOptions *options) {
    std::sort(results.begin(), results.end(), [](const RegexResult &a, const RegexResult &b) {
        return a.lineNumber < b.lineNumber;
    });

    for (const RegexResult &result: results) {
        if (options->showLineNumber) {
            std::cout << result.lineNumber << ":";
        }

        std::cout << *(result.matchedText) << std::endl;
    }
}


ResultExporter::ResultExporter() {

}
