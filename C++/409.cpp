#include <leetcode.h>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) mp[c]++;
        bool has_odd = false;
        int ans = 0;
        for (auto [_, n] : mp) {
            if (n % 2 == 0) {
                ans += n;
            } else {
                has_odd = true;
                ans += n - 1;
            }
        }
        return has_odd ? ans + 1 : ans;
    }
};