#include <leetcode.h>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> stat;
        for (auto n : nums) {
            stat[n]++;
        }
        using pii = pair<int, int>;
        auto cmp = [](const pii& x, const pii& y) { return x.second > y.second; };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
        for (auto [num, cnt] : stat) {
            q.emplace(num, cnt);
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};