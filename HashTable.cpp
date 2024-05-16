#include <unordered_map>
#include <string>
#include <sstream>

std::unordered_map<std::string, int> countWordFrequency(const std::string& text);
char firstNonRepeatingCharacter(const std::string& str);

int main() {
	std::unordered_map<int,int> map;


	return 0;
}

// A: Find the first non-repeating character in a string
char firstNonRepeatingCharacter(const std::string& str) {
    std::unordered_map<char, int> charCount;

    for (char c : str) {
        charCount[c]++;
    }
    for (char c : str) {
        if (charCount[c] == 1) {
            return c;
        }
    }
    return 0;
}

// B: Count the frequency of words in a text
std::unordered_map<std::string, int> countWordFrequency(const std::string& text) {
    std::unordered_map<std::string, int> wordFreq;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

        for (char& c : word) {
            c = std::tolower(c);
        }

        wordFreq[word]++;
    }

    return wordFreq;
}


// E: Implement a hash table from scratch
template<typename K, typename V, typename Hash = std::hash<K>>
class HashTable {
private:
    using Bucket = std::list<std::pair<K, V>>;
    std::vector<Bucket> table; 
    Hash hashFunction; 

public:
    explicit HashTable(size_t size = 10) : table(size) {}

    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key) % table.size(); 

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }

        table[index].emplace_back(key, value);
    }

    V* get(const K& key) {
        size_t index = hashFunction(key) % table.size(); 

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return &pair.second;
            }
        }

        return nullptr; 
    }
};
