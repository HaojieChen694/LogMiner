#include <string>

class TextFile {
public:
    explicit TextFile(const std::string& path);
    
    bool load();
    const std::string& path() const;
    const std::string& content() const;

private:
    std::string path_; // 文件路径
    std::string content_; // 文件内容
};
