//
// Created by Michael Molchanov on 24.10.2023.
//

#include "OptionParser.h"

std::unique_ptr<UserOptions> OptionParser::parse(CLI::App &app) {
    std::unique_ptr<UserOptions> options = std::make_unique<UserOptions>();

    app.add_flag("-i,--ignore-case", options->ignoreCase, "Perform a case insensitive search.");

    app.add_flag("-v,--invert-match", options->invertMatch, "Invert the sense of matching.");

    app.add_option("-e,--regex", options->patterns, "Specify the regex pattern.")
            ->required();

    app.add_option("-f,--file", options->inputFile, "File to search.");

    app.add_flag("-n,--line-number", options->showLineNumber, "Print line number with output.");

    app.add_option("--threads", options->threads, "Number of worker threads.");

    app.add_option("-l,--log", options->log_file, "Log file path (default: /dev/null)");

    app.add_flag("-s,--sequenced", options->unorderedOut, "Display results in sequence, if unset, display as soon as a match is found.");

    return options;
}

OptionParser::OptionParser() {

}
