#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for (int num : nums) {
            myset.insert(num);
        }
        return (myset.size() != nums.size())
    }
};