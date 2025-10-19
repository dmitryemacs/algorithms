#include <iostream>
#include <unordered_map>
#include <list>

template <typename KeyType, typename ValueType>
class LRUCache {
private:
    size_t capacity;
    std::list<std::pair<KeyType, ValueType>> cacheList;
    std::unordered_map<KeyType, typename std::list<std::pair<KeyType, ValueType>>::iterator> cacheMap;

public:
    LRUCache(size_t cap) : capacity(cap) {}

    void put(const KeyType& key, const ValueType& value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {

            cacheList.erase(it->second);
        } else {

            if (cacheMap.size() >= capacity) {
                auto last = cacheList.back();
                cacheMap.erase(last.first);
                cacheList.pop_back();
            }
        }

        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    bool get(const KeyType& key, ValueType& value) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return false;
        }
	
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        value = it->second->second;
        return true;
    }

    void printCache() {
        std::cout << "Cache contents (from most to least recently used):" << std::endl;
        for (const auto& pair : cacheList) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main() {
    LRUCache<int, std::string> cache(3);

    cache.put(1, "One");
    cache.put(2, "Two");
    cache.put(3, "Three");

    std::string value;
    if (cache.get(2, value)) {
        std::cout << "Found: " << value << std::endl;
    }

    cache.put(4, "Four");

    cache.printCache();
    return 0;
}
