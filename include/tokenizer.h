#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
public:
    static std::vector<std::string> tokenize(const std::string& str);

private:
    static bool is_word_char(unsigned char c);
};
#endif // TOKENIZER_H
