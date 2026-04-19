#include "query_engine.h"
#include <algorithm>

QueryEngine::QueryEngine(const InvertedIndex& index) : index_(index) {}

std::string QueryEngine::get_extension(const std::string& path) const{
    std::size_t pos = path.find_last_of('.');
    if(pos == std::string::npos){
        return "";
    }
    return path.substr(pos);
}

std::vector<SearchResult> QueryEngine::apply_options(std::vector<SearchResult> results,
                                                     const SearchOptions& options) const {
    if(options.use_extension_filter){
        results.erase(  //erase-remove 惯用法 删除容器元素的标准写法
            std::remove_if(results.begin(), results.end(), [this, &options](const SearchResult& r){
                return get_extension(r.path) != options.extension;
            }),
            results.end()
        );
        
    }

    std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b){
        return a.score > b.score; // 降序排序
    });

    if(results.size() > options.top_n){
        results.resize(options.top_n);
    }
    return results;

}

std::vector<SearchResult> QueryEngine::search_one(const std::string& term, const SearchOptions& options) const {
    
    std::vector<SearchResult> results;

    const std::vector<Posting>* postings = index_.find(term);

    if(!postings){
        return results; // 词条不存在 返回空结果
    }
    
    for(const Posting& p : *postings){
        results.emplace_back(index_.files()[p.fild_id].path, p.count);
    }

    return apply_options(results, options);
}
