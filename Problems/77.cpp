#include <leetcode.h>

class Solution1 {
private:
    vector<int> eg;
    vector<vector<int>> ans;

public:
    void dfs(int cur, int n, int k) {
        if (eg.size() + n - cur + 1 < k) {
            return;
        }
        if (eg.size() == k) {
            ans.push_back(eg);
            return;
        }
        eg.push_back(cur);
        dfs(cur + 1, n, k);
        eg.pop_back();
        dfs(cur + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(0, n, k);
        return ans;
    }
};

class Solution {
private:
    vector<int> eg;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k) {
        for (int i = 1; i <= k; ++i) {
            eg.push_back(i);
        }
        eg.push_back(n + 1);

        int i = 0;
        while (i < k) {
            ans.emplace_back(eg.begin(), eg.begin() + k);
            i = 0;
            while (i < k && eg[i] + 1 == eg[i + 1]) {
                eg[i] = i + 1;
                ++i;
            }
            ++eg[i];
        }
        return ans;
    }
};