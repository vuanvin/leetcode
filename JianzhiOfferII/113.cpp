#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        vector<int> pre_num(numCourses, 0);
        unordered_map<int, vector<int>> pre_map;

        for (auto & pre : prerequisites) {
            auto a = pre[0], b = pre[1];
            pre_num[a]++;
            if (pre_map.count(b)) {
                pre_map[b].push_back(a);
            } else {
                pre_map[b] = {a};
            }
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (pre_num[i] == 0) Q.push(i);
        }

        while (!Q.empty()) {
            auto v = Q.front(); Q.pop();
            res.push_back(v);
            for (auto u : pre_map[v]) {
                pre_num[u]--;
                if (pre_num[u] == 0) Q.push(u);
            }
        }

        return (res.size() == numCourses ? res : vector<int>());
    }
};