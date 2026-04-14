#include "file_scanner.h"

#include <dirent.h> // 目录结构体
#include <sys/stat.h> // 文件状态结构体

#include <cstring> // 字符串操作函数
#include <iostream>

namespace { // 匿名命名空间  本文件私有区域 只在当前 .cpp 有效
    // 合并目录和文件名
    std::string join_path(const std::string& dir, const std::string& file) {
        if(dir.empty()) {
            return file;
        }
        if(dir[dir.size() - 1] == '/') {  // 检查目录是否以斜杠结尾
            return dir + file;
        }
        return dir + "/" + file;
    }
    std::string get_extension(const std::string& path) {
        std::size_t pos = path.find_last_of('.'); // 查找最后一个点的位置
        if(pos == std::string::npos) { // 如果没有找到点
            return "";
        }
        return path.substr(pos); // 返回从点开始的子字符串
    }   
}

FileScanner::FileScanner(std::vector<std::string> extensions)
    : allowed_extensions_(std::move(extensions)) {}   // 移动构造函数

bool FileScanner::is_dir(const std::string& path) const {
    struct stat st; // 文件状态结构体
    if(stat(path.c_str(), &st) == -1) { // 获取文件状态
        return false;
    }
    return S_ISDIR(st.st_mode); // 检查是否为目录
}

bool FileScanner::is_regular_file(const std::string& path) const {
    struct stat st; // 文件状态结构体
    if(stat(path.c_str(), &st) == -1) { // 获取文件状态
        return false;
    }
    return S_ISREG(st.st_mode); // 检查是否为普通文件
}

bool FileScanner::is_allowed_file(const std::string& path) const {
    if(!is_regular_file(path)) {
        return false;
    }
    const std::string ext = get_extension(path); // 获取文件扩展名
    for(std::size_t i = 0; i < allowed_extensions_.size(); i++) {
        if(allowed_extensions_[i] == ext) {
            return true;
        }
    }
    return false;
}

void FileScanner::scan_recursive(const std::string& dir, std::vector<std::string>& files) const {
    if(!is_dir(dir)) {
        return;
    }
    DIR* dp = opendir(dir.c_str()); // 打开目录 DIR* 指针
    if(dp == nullptr) {
        std::cerr << "[Warning] Cannot open directory: " << dir << std::endl;
        return;
    }

    struct dirent* ep; // 目录结构体指针
    while((ep = readdir(dp)) != nullptr) {  // 读取目录中的文件 readdir 返回一个目录结构体指针
        std::string file = ep->d_name; // 获取文件名
        if(file == "." || file == "..") { // 跳过当前目录和父一级目录
            continue;
        }
        std::string path = join_path(dir, file); // 合并目录和文件名
        if(is_allowed_file(path)) { // 检查文件是否在允许列表中
            files.push_back(path); // 添加到文件列表
        }else if(is_dir(path)) { // 检查是否为目录
            scan_recursive(path, files); // 递归扫描子目录
        }
    }
    closedir(dp); // 关闭目录
}

std::vector<std::string> FileScanner::scan(const std::string& root_dir) const { 
    std::vector<std::string> files;
    scan_recursive(root_dir, files);
    return files;
}

