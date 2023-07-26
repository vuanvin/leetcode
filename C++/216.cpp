#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> eg;

    void dfs(int start, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(eg);
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }
        for (int i = start; i < 10; ++i) {
            eg.push_back(i);
            dfs(i + 1, k - 1, n - i);
            eg.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};