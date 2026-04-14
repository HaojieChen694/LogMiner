#include "stats_report.h"

#include <iostream>

void StatsReport::add(const FileStatItem& item) {
    items_.push_back(item);
}

std::size_t StatsReport::total_files() const {
    return items_.size();
}

std::size_t StatsReport::total_lines() const {
    std::size_t total = 0;
    for(const auto& item : items_){
        total += item.stats.total_lines;
    }
    return total;
}

std::size_t StatsReport::total_words() const {
    std::size_t total = 0;
    for(const auto& item : items_){
        total += item.stats.total_words;
    }
    return total;
}

std::size_t StatsReport::total_chars() const {
    std::size_t total = 0;
    for(const auto& item : items_){
        total += item.stats.total_chars;
    }
    return total;
}

void StatsReport::print_details() const {
    std::cout << "Details:\n";
    for (std::size_t i = 0; i < items_.size(); ++i) {
        const FileStatItem& item = items_[i];
        std::cout << "  " << item.path
                  << " | lines=" << item.stats.total_lines
                  << " words=" << item.stats.total_words
                  << " chars=" << item.stats.total_chars
                  << std::endl;
    }
}

void StatsReport::print_summary() const {
    std::cout << "\nSummary:\n";
    std::cout << "  files = " << total_files() << std::endl;
    std::cout << "  lines = " << total_lines() << std::endl;
    std::cout << "  words = " << total_words() << std::endl;
    std::cout << "  chars = " << total_chars() << std::endl;
}