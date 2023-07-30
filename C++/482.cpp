#include <leetcode.h>

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        string res;
        for (int i = s.size() - 1; i >= 0; i--) {
            auto c = s[i];
            if (isalnum(c)) {
                if (cnt != 0 && cnt % k == 0) {
                    res += '-';
                }
                
                res += toupper(c);
                cnt++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};