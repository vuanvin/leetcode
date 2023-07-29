#include <leetcode.h>

class Solution {
private:
    unordered_set<int> seen;
    int left;
    int k;
    string ans;

public:
    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int neigh = node * 10 + x;
            if (!seen.count(neigh)) {
                seen.insert(neigh);
                dfs(neigh % left);
                ans += (x + '0');
            }
        }
    }
    string crackSafe(int n, int k) {
        left = pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};