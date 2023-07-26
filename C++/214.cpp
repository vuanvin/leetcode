#include <leetcode.h>

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> next(n, -1);
        for (int l = 0, r = 1; r < n; ++l, ++r) {
            next[r] = l;
            if (s[l] == s[r]) {
                while ((next[r] = next[next[r]]) >= 0 && s[next[r]] == s[r])
                    ;
            } else {
                while ((l = next[l]) >= 0 && s[l] != s[r])
                    ;
            }
        }
        int j = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (j >= 0 && s[j] != s[i]) j = next[j];
            j += 1;
        }
        auto add = j == n ? "" : s.substr(j);
        reverse(add.begin(), add.end());
        return add + s;
    }
};