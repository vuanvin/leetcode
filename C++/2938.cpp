#include <leetcode.h>

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, cnt = 0;
        for (auto c : s) {
            if (c == '0') {
                ans += cnt;
            } else {
                cnt++;
            }
        }
        return ans;
    }
};