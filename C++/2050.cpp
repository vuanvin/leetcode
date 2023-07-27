#include <leetcode.h>

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans = 0;
        vector<int> start(n, 0), fa(n, 0);
        unordered_map<int, vector<int>> relationMap;
        for (const auto& r : relations) {
            relationMap[r[0] - 1].push_back(r[1] - 1);
            fa[r[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (fa[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            int end_time = start[u] + time[u];
            ans = max(ans, end_time);
            for (auto v : relationMap[u]) {
                start[v] = max(start[v], end_time);
                fa[v]--;
                if (fa[v] == 0) q.push(v);
            }
        }
        return ans;
    }
};