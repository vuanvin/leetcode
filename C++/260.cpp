#include <leetcode.h>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0, mask = 1;
        for (auto num : nums) temp ^= num;
        while (!(mask & temp)) mask <<= 1;
        int num1 = 0, num2 = 0;
        for (auto num : nums) {
            if (num & mask) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};