#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> mp;
    vector<pair<int, int>> pos;
    vector<int> ans;

    void df(vector<int>& nums, int prev, int curr, int deep) {
        int val = nums[curr];

        // node
        int max_dp = -1;
        for (int sel = 1; sel <= 50; sel++) {
            auto [v_id, v_dp] = pos[sel];

            if (v_dp != -1 && gcd(sel, val) == 1) {
                if (ans[curr] == -1) {
                    ans[curr] = v_id;
                    max_dp = v_dp;
                } else {
                    if (v_dp > max_dp) {
                        ans[curr] = v_id;
                        max_dp = v_dp;
                    }
                }
            }
        }

        auto [old_id, old_dp] = pos[val];
        pos[val].first = curr;
        pos[val].second = deep;

        // visit
        while (mp[curr].size()) {
            auto next = mp[curr].back();
            mp[curr].pop_back();

            if (next == prev) continue;
            df(nums, curr, next, deep + 1);
        }

        pos[val].first = old_id;
        pos[val].second = old_dp;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        mp.assign(nums.size(), vector<int>());
        pos.assign(51, pair<int, int>(-1, -1));
        ans.assign(nums.size(), -1);

        for (auto& e : edges) {
            int x = e[0], y = e[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }

        df(nums, -1, 0, 0);

        return ans;
    }
};