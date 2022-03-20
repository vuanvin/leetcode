#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        function<void(int)> Find;
        Find = [&] (int n) {
            if (n == nums.size()) { ans.push_back(nums); }
            for (int i = n; i < nums.size(); i++) {
                swap(nums[i], nums[n]);
                Find(n + 1);
                swap(nums[i], nums[n]);
            }
        };
        Find(0);
        return ans;
    }
};