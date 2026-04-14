#ifndef STATS_REPORT_H
#define STATS_REPORT_H

#include "text_stats.h"

#include <string>
#include <vector>

struct FileStatItem {
    std::string path;
    TextStats stats;
};

class StatsReport {
public:
    void add(const FileStatItem& item);

    std::size_t total_files() const;
    std::size_t total_lines() const;
    std::size_t total_words() const;
    std::size_t total_chars() const;

    void print_details() const;
    void print_summary() const;

private:
    std::vector<FileStatItem> items_;
};

#endif