#include <leetcode.h>

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0, 1};
        for (int i = 1; i < n; ++i) {
            int base = 1 << i;
            for (int j = base - 1; j >= 0; --j) {
                ans.push_back(base + ans[j]);
            }
        }
        return ans;
    }
};