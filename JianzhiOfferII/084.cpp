#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> num_cnt;
    vector<int> arr;

    void dfs(int n) {
        if (n == 0) {
            ans.push_back(arr);
            return;
        }

        for (auto & item : num_cnt) {
            if (item.second > 0) {
                item.second--;
                arr.push_back(item.first);
                dfs(n - 1);
                arr.pop_back();
                item.second++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto num : nums) {
            if (num_cnt.count(num)) {
                num_cnt[num]++;
            } else {
                num_cnt[num] = 1;
            }
        }

        int n = nums.size();
        dfs(n);

        return ans;
    }
};