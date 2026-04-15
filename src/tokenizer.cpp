#include "tokenizer.h"

#include <cctype> 

bool Tokenizer::is_word_char(unsigned char c) {
    return std::isalnum(c) != false; // 判断是否为字母、数字或下划线
}

std::vector<std::string> Tokenizer::tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::string current_token;
    // 空格充当分隔符
    for (size_t i = 0; i < str.size(); ++i) { // 遍历输入字符串
        unsigned char c = static_cast<unsigned char>(str[i]); //static_cast 转换为无符号字符类型
        if (is_word_char(c)) {
            current_token.push_back(static_cast<char>(std::tolower(c))); // 如果是单词字符，添加到当前 token，转为小写
        } else {
            if (!current_token.empty()) {
                tokens.push_back(current_token); // 将当前 token 添加到结果列表
                current_token.clear(); // 清空当前 token
            }
        }
    }

    // 最后检查是否还有未添加的 token
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }

    return tokens;
}
