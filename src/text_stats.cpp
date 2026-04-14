#include "text_stats.h"
#include <cctype>

bool TextAnalyzer::is_word_char(unsigned char c) {
    return std::isalnum(c) != 0; // isalnum 返回 0 表示不是字母或数字
}

TextStats TextAnalyzer::analyze(const std::string& text) {
    TextStats stats;
    stats.total_chars = text.size();
    if(!text.empty()){
        stats.total_lines = 1;
        for(std::size_t i = 0; i < text.size(); ++i){
            if(text[i] == '\n'){
                ++stats.total_lines;
            }
        }
    }
    bool in_word = false;
    for(std::size_t i = 0; i < text.size(); ++i){
        unsigned char c = static_cast<unsigned char>(text[i]);
        if(is_word_char(c)){
            if(!in_word){
                ++stats.total_words;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }
    return stats;
}
