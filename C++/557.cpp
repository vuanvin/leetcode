#include <leetcode.h>

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        for (int j = 0 ; j < n; j++) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};