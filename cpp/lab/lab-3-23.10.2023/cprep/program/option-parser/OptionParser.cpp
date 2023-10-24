//
// Created by Michael Molchanov on 24.10.2023.
//

#include "OptionParser.h"

std::unique_ptr<Options> OptionParser::parse(CLI::App &app) {
    std::unique_ptr<Options> options = std::make_unique<Options>();

    app.add_flag("-i,--ignore-case", options->ignoreCase, "Perform a case insensitive search.");

    // Invert match
    app.add_flag("-v,--invert-match", options->invertMatch, "Invert the sense of matching.");

    // Regex pattern (e.g., for -e option)
    app.add_option("-e,--regex", options->patterns, "Specify the regex pattern.")
            ->required();

    // File to search
    app.add_option("-f,--file", options->inputFile, "File to search.");

    // Line number
    app.add_flag("-n,--line-number", options->showLineNumber, "Print line number with output.");

    // Number of threads
    app.add_option("--threads", options->threads, "Number of worker threads.");
}

OptionParser::OptionParser() {

}
