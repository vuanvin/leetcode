#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sample;

        function<void(int)> Find;
        int n = nums.size();
        Find = [&] (int k) {
            if (k == n) {
                ans.push_back(sample);
                return;
            }
            Find(k + 1);
            sample.push_back(nums[k]);
            Find(k + 1);
            sample.pop_back();
        };
        Find(0);

        return ans;
    }
};