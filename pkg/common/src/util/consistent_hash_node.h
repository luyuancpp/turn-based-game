#pragma once

#include <map>
#include <functional> 
#include <algorithm>

//https://github.com/ioriiod0/consistent_hash/blob/master/test.cpp
//https://zhuanlan.zhihu.com/p/482549860

template <typename Key,
    typename Value>
class ConsistentHashNode
{
public:

    using NodeListType = std::map<Key, Value>;
    
public:
    std::size_t size() const { return nodes_.size(); }

    bool empty() const { return nodes_.empty(); }

    decltype(auto) add(Key id, const Value& node)
    {
        auto hash_id = std::hash<Key>{}(id);
        return nodes_.emplace(hash_id, node); 
    }

    void remove(Key id)
    {
        auto hash_id = std::hash<Key>{}(id);
        nodes_.erase(hash_id);
    }

    decltype(auto) get_by_id(Key id)
    {
        auto hash_id = std::hash<Key>{}(id);
        return nodes_.find(hash_id);
    }

    decltype(auto) get_by_hash(Key hash) 
    {
        if (nodes_.empty()) {
            return nodes_.end();
        }

        auto it = nodes_.lower_bound(hash);
        if (it == nodes_.end()) {
            it = nodes_.begin();
        }

        return it;
    }

    decltype(auto) begin() { return nodes_.begin(); }
    decltype(auto) end() { return nodes_.end(); }

private:
    NodeListType nodes_;
};


