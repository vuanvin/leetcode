#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        auto n = colsum.size();
        int cnt[3] = {0};
        for (auto s : colsum) { cnt[s] += 1; }
        if (upper + lower != cnt[2] * 2 + cnt[1] || lower > cnt[2] + cnt[1] || upper > cnt[2] + cnt[1]) {
            return vector<vector<int>>();
        } 
        vector<vector<int>> ans(2, vector<int>(n, 0));
        auto upper_cnt = upper - cnt[2];
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper_cnt > 0) {
                    ans[0][i] = 1;
                    --upper_cnt;
                } else {
                    ans[1][i] = 1;
                }
            }
        }
        return ans;
    }
};