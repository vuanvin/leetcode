#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;

        std::function<void(int)> find;
        find = [&](int x) {
            path.push_back(x);
            if (x == n - 1) { ans.push_back(path); }
            else {
                for (auto y : graph[x]) { find(y); }
            }
            path.pop_back();
        };

        find(0);
        return ans;
    }
};