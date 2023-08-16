#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t.[i]) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }

        int mycount[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            mycount[s[i] - 'a']++;
            mycount[t[i] - 'a']--;
        }

        for (int val : mycount) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};