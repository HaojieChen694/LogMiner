#include "app.h"
#include "file_scanner.h"
#include "indexer.h"
#include "query_engine.h"
#include "text_file.h"
#include "tokenizer.h"

#include <iostream>
#include <string>
#include <vector>

int App::run(int argc, char* argv[]) const {
    if (argc < 3) {
        std::cout << "Usage: ./logminer <directory> <term>\n";
        return 1;
    }

    std::string input_dir = argv[1];
    std::string term = argv[2];

    FileScanner scanner(std::vector<std::string>{".txt", ".log", ".md"});
    std::vector<std::string> files = scanner.scan(input_dir);

    InvertedIndex index;

    for (std::size_t i = 0; i < files.size(); ++i) {
        TextFile file(files[i]);
        if (!file.load()) {
            continue;
        }

        std::vector<std::string> tokens = Tokenizer::tokenize(file.content());
        index.add_document(files[i], tokens);
    }

    QueryEngine engine(index);
    SearchOptions options;
    std::vector<SearchResult> results = engine.search_one(term, options);

    std::cout << "Search term: " << term << std::endl;
    std::cout << "Matched files: " << results.size() << std::endl;

    for (std::size_t i = 0; i < results.size(); ++i) {
        std::cout << "  " << results[i].path
                  << " | score=" << results[i].score
                  << std::endl;
    }

    return 0;
}