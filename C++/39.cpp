#include <leetcode.h>

class Solution {
public:
    // vector<vector<int>> combinationsum(vector<int>& candidates, int target) {
    //     vector<vector<int>> ans;
    //     vector<int> ids;
    //     int n = candidates.size(), sum = 0;

    //     ids.push_back(0);
    //     sum += candidates[0];

    //     while (!ids.empty()) {
    //         if (sum < target) {
    //             ids.push_back(ids.back());
    //             sum += candidates[ids.back()];
    //         } else {
    //             if (sum == target) {
    //                 vector<int> nums(ids.size());
    //                 for (int i = 0; i < ids.size(); i++) {
    //                     nums[i] = candidates[ids[i]];
    //                 }
    //                 ans.emplace_back(std::move(nums));
    //             }

    //             while (ids.back() >= n - 1) {
    //                 sum -= candidates[ids.back()];
    //                 ids.pop_back();
    //                 if (ids.empty()) return ans;
    //             }

    //             sum -= candidates[ids.back()];
    //             ids.back()++;
    //             sum += candidates[ids.back()];
    //         }
    //     }

    //     return ans;
    // }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};