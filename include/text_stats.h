#ifndef TEXT_STATS_H
#define TEXT_STATS_H

#include <cstddef> // 包含 size_t 类型
#include <string>

struct TextStats {
    std::size_t total_lines = 0;
    std::size_t total_words = 0;
    std::size_t total_chars = 0;
};

class TextAnalyzer {
public:
    static TextStats analyze(const std::string& text); // 分析文本统计信息
private:
    static bool is_word_char(unsigned char c);
};
#endif