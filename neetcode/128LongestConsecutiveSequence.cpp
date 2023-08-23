#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> interval;
        int biggestLength = 0;

        for (auto& num : nums) {
            if (interval.count(num)) {
                continue;
            } else {
                interval[num] = num;
            }

            int smallerSide = num, biggerSide = num;
            if (interval.count(num - 1)) {
                smallerSide = interval[num - 1];
            }
            if (interval.count(num + 1)) {
                biggerSide = interval[num + 1];
            }

            interval[smallerSide] = biggerSide;
            interval[biggerSide] = smallerSide;
            biggestLength = max(biggestLength, biggerSide - smallerSide + 1);
        }
        return biggestLength;
    }


    int longestConsecutive2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int i0 = i;
            for (++i; i < n && nums[i-1] + 1 >= nums[i]; ++i);
            ans = max(ans, nums[i-1] - nums[i0] + 1);
        }
        return ans;
    }

    int longestConsecutive3(vector<int>& nums) {
        int min = 2147483647;
        int max = -2147483647;
        for (int& num : nums) {
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
        vector<bool> bits(max - min + 1);
        for (int num : nums) {
            bits[num - min] = 1;
        }
        int current = 0;
        int result = 0;
        for (bool bit : bits) {
            if (bit > 0) {
                current++;
            } else {
                if (current > result) {
                    result = current;
                }
                current = 0;
            }
        }
        if (current > result) {
            result = current;
        }
        return result;
    }
};