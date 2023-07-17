#include <leetcode.h>

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add > 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};