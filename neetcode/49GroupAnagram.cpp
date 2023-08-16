#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct ArrayHasher {
        std::size_t operator()(const std::array<int, 26>& a) const {
            std::size_t h = 0;

            for (auto e : a) {
                h ^= std::hash<int>{}(e)  + 0x9e3779b9 + (h << 6) + (h >> 2); 
            }
            return h;
        }   
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        array<int, 26> mycount = {0};
        unordered_map<array<int, 26>, vector<string>, ArrayHasher> mymap;

        for (auto&& str : strs) {
            countChars(str, mycount);
            mymap[mycount].emplace_back(move(str));
            fill(mycount.begin(), mycount.end(), 0);
        }

        vector<vector<string>> result;
        result.reserve(mymap.size());

        for (auto &&[_, anagram_group] : mymap) {
            result.emplace_back(std::move(anagram_group));
        }

        return result;


    }

    void countChars(string& str, array<int, 26> mycount) {
        for (char c : str) {
            mycount[c - 'a']++;
        }
    }
};