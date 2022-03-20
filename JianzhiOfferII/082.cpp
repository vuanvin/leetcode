#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> sample;

        int n = candidates.size();

        function<void(int, int)> dp;

        dp = [&] (int k, int sum) {
            if (sum == target) {
                ans.push_back(sample);
            } else if (k == n || sum > target) {
                return;
            }

            int k2 = k;
            while (k2 < n && candidates[k] == candidates[k2]) k2++;

            dp(k2, sum);
            for (int j = k; j < k2; j++) {
                sample.push_back(candidates[k]);
                sum += candidates[k];
                dp(k2, sum);
            }

            for (int j = k; j < k2; j++) { sample.pop_back(); }
        };

        dp(0, 0);

        return ans;
    }
};