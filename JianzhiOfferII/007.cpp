#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int k = 0; k < n-2; k++) {
        if (k > 0 && nums[k] == nums[k-1]) continue;
        int target = -nums[k];
        int i = k + 1, j = n-1;
        while (i < j) {
            int a = nums[i], b = nums[j];
            if (a + b == target) {
                res.push_back({nums[k], a, b});
                while (i < j && nums[i] == nums[++i]) ;
                while (i < j && nums[j] == nums[--j]) ;
            } else if (a + b < target) {
                i ++;
            } else {
                j --;
            }
        }

    }
    return res;
}