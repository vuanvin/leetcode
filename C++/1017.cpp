#include <leetcode.h>

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while (n) {
            if (n % 2 == 0) {
                ans += '0';
            } else {
                n -= 1;
                ans += '1';
            }
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};