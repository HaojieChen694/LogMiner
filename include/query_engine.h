#ifndef QUERY_ENGINE_H
#define QUERY_ENGINE_H

#include "indexer.h"

#include <cstddef>
#include <string>
#include <vector>

struct SearchOptions {
    bool use_extension_filter;
    std::string extension;
    std::size_t top_n;

    SearchOptions():use_extension_filter(false), extension(""), top_n(10) {}
};

struct SearchResult{
    std::string path;
    std::size_t score;

    SearchResult() : score(0) {}
    SearchResult(const std::string& p, std::size_t s) : path(p), score(s) {}
};

class QueryEngine{
public:
    QueryEngine(const InvertedIndex& index);
    std::vector<SearchResult> search_one(const std::string& term, const SearchOptions& options) const;

private:
    std::vector<SearchResult> apply_options(std::vector<SearchResult> results, const SearchOptions& options) const;
    std::string get_extension(const std::string& path) const;
    const InvertedIndex& index_;
};

#endif // QUERY_ENGINE_H