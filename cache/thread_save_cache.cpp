#include <iostream>
#include <list>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <chrono>

template <typename Key, typename Value>
class ThreadSafeLRUCache {
public:
    explicit ThreadSafeLRUCache(size_t capacity) : capacity(capacity) {}

    // Получить значение по ключу
    Value* get(const Key& key) {
        std::lock_guard<std::mutex> lock(mtx);

        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            std::cout << "Miss: " << key << std::endl;
            return nullptr;
        }

        // Перемещаем элемент в начало списка — теперь он "свежий"
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        std::cout << "Hit: " << key << std::endl;
        return &it->second->second;
    }

    // Добавить или обновить элемент
    void put(const Key& key, const Value& value) {
        std::lock_guard<std::mutex> lock(mtx);

        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }

        if (cacheList.size() >= capacity) {
            auto oldKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(oldKey);
            std::cout << "Evicted: " << oldKey << std::endl;
        }

        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    void printCache() const {
        std::lock_guard<std::mutex> lock(mtx);

        std::cout << "Cache: ";
        for (const auto& p : cacheList) {
            std::cout << "(" << p.first << ":" << p.second << ") ";
        }
        std::cout << std::endl;
    }

private:
    size_t capacity;
    mutable std::mutex mtx; // защищает cacheList и cacheMap
    std::list<std::pair<Key, Value>> cacheList;
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap;
};

void writer(ThreadSafeLRUCache<int, std::string>& cache) {
    for (int i = 0; i < 10; ++i) {
        cache.put(i, "val_" + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void reader(ThreadSafeLRUCache<int, std::string>& cache) {
    for (int i = 0; i < 10; ++i) {
        cache.get(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    ThreadSafeLRUCache<int, std::string> cache(5);

    std::thread t1(writer, std::ref(cache));
    std::thread t2(reader, std::ref(cache));

    t1.join();
    t2.join();

    cache.printCache();
    return 0;
}

