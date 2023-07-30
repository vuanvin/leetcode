#include <leetcode.h>

class Solution {
public:
    int countSegments(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l++;
        while (l <= r && s[r] == ' ') r--;
        if (l > r) return 0;
        int ans = 1;
        for (; l < r; l++) {
            if (s[l] == ' ' && s[l+1] != ' ') {
                ans ++;
            }
        }
        return ans;
    }
};