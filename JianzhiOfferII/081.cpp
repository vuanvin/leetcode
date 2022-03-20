#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sample;

        int n = candidates.size();
        function<void(int, int)> Find;
        Find = [&] (int k, int sum) {
            if (sum == target) {
                ans.push_back(sample);
                return;
            } else if (k == n || sum > target) {
                return;
            }

            sample.push_back(candidates[k]);
            Find(k, sum + candidates[k]);
            sample.pop_back();

            Find(k + 1, sum);
        };

        Find(0, 0);
        return ans;
    }
};