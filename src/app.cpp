#include "app.h"
#include "file_scanner.h"
#include "stats_report.h"
#include "text_file.h"
#include "text_stats.h"
#include "tokenizer.h"


#include <iostream>
#include <string>
#include <vector>

int App::run(int argc, char* argv[]) const {
    // if (argc < 2) {
    //     std::cout << "Usage: ./logminer <directory>\n";
    //     return 1;
    // }

    // std::string input_dir = argv[1];

    // FileScanner scanner(std::vector<std::string>{".txt", ".log", ".md"});
    // std::vector<std::string> files = scanner.scan(input_dir);

    // StatsReport report;

    // for (std::size_t i = 0; i < files.size(); ++i) {
    //     TextFile file(files[i]);
    //     if (!file.load()) {
    //         std::cout << "[Skip] Cannot open: " << files[i] << std::endl;
    //         continue;
    //     }

    //     FileStatItem item;
    //     item.path = files[i];
    //     item.stats = TextAnalyzer::analyze(file.content());

    //     report.add(item);
    // }

    // report.print_details();
    // report.print_summary();

    std::string text = "Hello, C_11 World! hello 123";
    std::vector<std::string> tokens = Tokenizer::tokenize(text);

    for (std::size_t i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i] << std::endl;
    }

    return 0;
}