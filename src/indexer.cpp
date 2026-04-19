#include "indexer.h"

void InvertedIndex::add_document(const std::string& path,
                                const std::vector<std::string>& tokens) {
    std::size_t file_id = files_.size();
    files_.push_back(IndexedFile(file_id, path));

    std::unordered_map<std::string, std::size_t> local_freq;
    for (std::size_t i = 0; i < tokens.size(); ++i) {
        ++local_freq[tokens[i]];
    }

    for (auto it = local_freq.begin(); it != local_freq.end(); ++it) {
        index_[it->first].push_back(Posting(file_id, it->second));
    }
}

const std::vector<IndexedFile>& InvertedIndex::files() const {
    return files_;
}

const std::vector<Posting>* InvertedIndex::find(const std::string& term) const {
    std::unordered_map<std::string, std::vector<Posting>>::const_iterator it = index_.find(term);
    if (it == index_.end()) {
        return NULL;
    }
    return &(it->second);
}
