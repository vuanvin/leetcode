#include <leetcode.h>

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) {
            return s;
        }

        int cnt = 0, l = 0;
        vector<string> ss;
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    ss.push_back("1" + makeLargestSpecial(s.substr(l + 1, r - l - 1)) + "0");
                    l = r + 1;
                }
            }
        }
        sort(ss.begin(), ss.end(), greater<string>());
        return accumulate(ss.begin(), ss.end(), "");
    }
};