#include <string>;
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string final;
        final.resize(word1.length() + word2.length());
        string::iterator it1 = word1.begin();
        string::iterator it2 = word2.being();

        while (it1 != word1.end() && it2 != word2.end()) {
            final.push_back(*it1);
            final.push_back(*it2);
            it1++;
            it2++;
        }
        while (it1 != word1.end()) {
            final.push_back(*it1);
            it1++
        }
        while (it1 != word1.end() && it2 != word2.end()) {
            final.push_back(*it2);
            it2++;
        }
        
        return final;
    }
};