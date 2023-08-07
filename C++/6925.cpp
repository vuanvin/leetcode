#include <leetcode.h>

class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++) {
            auto ch = s[i];
            if (ch == 'i') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};