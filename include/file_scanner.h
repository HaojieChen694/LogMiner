#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include <string>
#include <vector>

class FileScanner {
public:
    explicit FileScanner(std::vector<std::string> allowed_extensions); // 显式构造函数

    std::vector<std::string> scan(const std::string& root_dir) const; //不能修改引用 扫描文件

private:
    void scan_recursive(const std::string& dir, std::vector<std::string>& files) const; // 递归扫描目录

    bool is_allowed_file(const std::string& path) const; // 检查文件是否在允许列表中
    bool is_dir(const std::string& path) const; // 检查目录是否存在
    bool is_regular_file(const std::string& path) const; // 检查目录是否为普通目录
   
    std::vector<std::string> allowed_extensions_; // 允许的文件扩展名列表
};
#endif
