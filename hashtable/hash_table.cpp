#include <iostream>
#include <vector>
#include <utility>
#include <list>

template<class Key, class Value>
class HashMap {
    private:
        std::vector<std::list<std::pair<Key, Value>>> map;
        int size;

        int hashFunction(const Key& key) const {
            return std::hash<Key>{}(key) % size;
        }

    public:
        HashMap(int sizeMap = 10) : size(sizeMap) {
            map.resize(size);
        }

        void insert(const Key& key, const Value& value) {
            int index = hashFunction(key);
            for(auto& pair : map[index]) {
                if(pair.first == key) {
                    pair.second = value;
                    return;
                }
            }
            map[index].emplace_back(key, value);
        }

        Value* search(const Key& key) {
            int index = hashFunction(key);
            for(auto& pair : map[index]) {
                if(pair.first == key) {
                    return &pair.second;
                }
            }
            return nullptr;
        }

        bool remove(const Key& key) {
            int index = hashFunction(key);
            auto& chain = map[index];
            for(auto it = chain.begin(); it != chain.end(); ++it) {
                if(it->first == key) {
                    chain.erase(it);
                    return true;
                }
            }
            return false;
        }

        void print() const {
            for(int i = 0; i < size; i++) {
                std::cout << "Bucket: " << i << ": ";
                for(const auto& pair : map[i]) {
                    std::cout << "[" << pair.first << " => " << pair.second << "] ";
                }
                std::cout << "\n";
            }
        }
};

int main(int argc, char *argv[]) {
    HashMap<int, int> hashmap;
    hashmap.insert(1, 1);
    hashmap.insert(2, 20);
    hashmap.insert(3, 300);
    hashmap.insert(4, 4000);
    hashmap.insert(5, 50000);

    int* value = hashmap.search(3);
    if(value) {
        std::cout << "Found: " << *value << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    std::cout << "HashMap: " << std::endl;
    hashmap.print();

    std::cout << "Removed chain in hashmap: " << std::endl;
    hashmap.remove(3);
    hashmap.print();

    return 0;
}
