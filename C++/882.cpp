#include <leetcode.h>

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> S;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                S.insert(fronts[i]);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            auto u = backs[i], v = fronts[i];
            if (!S.count(u)) {
                ans = min(ans, u);
            }
            if (!S.count(v)) {
                ans = min(ans, v);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};