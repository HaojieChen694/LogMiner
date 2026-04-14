#include "text_file.h"

#include <fstream> // 文件流
#include <sstream> // 字符串流

TextFile::TextFile(const std::string& path) : path_(path) {} // 构造函数

bool TextFile::load() {
    std::ifstream file(path_.c_str());  // 读文件 input file input stream
    if (!file.is_open()) {
        return false;
    }
    std::ostringstream oss; // 字符串流
    oss << file.rdbuf(); // 把文件内容读进字符串流
    content_ = oss.str(); // 把字符串流的内容赋值给 content_
    return true;
}
const std::string& TextFile::path() const {
    return path_;
}

const std::string& TextFile::content() const {
    return content_;
}

/*
1. std::ifstream 用于读取文件
2. std::ostringstream 把整个文件内容读进字符串
3. const std::string& 避免不必要复制
4. 类的职责单一
今天新增一个类：TextFile
它只负责一件事：读文件
*/