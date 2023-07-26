#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        using pii = pair<int, int>;
        auto cmp = [](const pii& a, const pii& b) { return a.second < b.second; };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        vector<vector<int>> ans;
        int n = buildings.size(), idx = 0;
        for (auto& boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                q.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!q.empty() && q.top().first <= boundary) {
                q.pop();
            }
            int maxn = q.empty() ? 0 : q.top().second;
            if (ans.size() == 0 || maxn != ans.back()[1]) {
                ans.push_back({boundary, maxn});
            }
        }
        return ans;
    }
};