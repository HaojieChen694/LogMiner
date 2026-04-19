#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <unordered_map> // 用于索引
#include <vector>
#include <cstddef>

struct Posting{
    std::size_t fild_id; // 字段ID
    std::size_t count;  // 发现次数

    Posting() : fild_id(0), count(0) {}
    Posting(std::size_t fid, std::size_t c) : fild_id(fid), count(c) {}

};

struct IndexedFile {
    std::size_t id; // 文件ID
    std::string path; // 文件路径

    IndexedFile() : id(0) {}
    IndexedFile(std::size_t id, const std::string& path) : id(id), path(path) {}
};

class InvertedIndex {
public:
    void add_document(const std::string& path,
                    const std::vector<std::string>& tokens);
    const std::vector<IndexedFile>& files() const;
    const std::vector<Posting>* find(const std::string& term) const;
private:
    std::vector<IndexedFile> files_; // 所有文件
    std::unordered_map<std::string, std::vector<Posting>> index_; // 词 -> Posting列表
};

#endif // INDEXER_H
