#include <leetcode.h>

class Solution {
public:
    vector<vector<string>> ans;
    vector<int> solution;
    unordered_set<int> uniq;

    void dfs(int k, int n) {
        if (k == n) {
            ans.push_back(vector<string>(n, string(n, '.')));
            for (int i = 0; i < n; ++i) {
                ans.back()[i][solution[i]] = 'Q';
            }
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (uniq.count(i) || uniq.count(n + k + i) || uniq.count(-n - k + i)) {
                continue;
            }
            uniq.insert(i);
            uniq.insert(n + k + i);
            uniq.insert(-n - k + i);

            solution[k] = i;
            dfs(k + 1, n);

            uniq.erase(i);
            uniq.erase(n + k + i);
            uniq.erase(-n - k + i);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        solution.resize(n);
        dfs(0, n);
        return ans;
    }
};