#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n, vector<int>());
        vector<set<int>> sun(n, set<int>()), grn(n, set<int>());
        vector<int> dep(n, 0);

        for (auto& e : edges) {
            sun[e[0]].insert(e[1]);
            grn[e[1]].insert(e[0]);
        }

        queue<int> Q;
        for (int i = 0; i < n; i++) {
            dep[i] = grn[i].size();
            if (dep[i] == 0) {
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            for (auto i : sun[p]) {
                dep[i]--;
                if (dep[i] == 0) {
                    Q.push(i);
                }
                for (auto q : grn[p]) {
                    grn[i].insert(q);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto p : grn[i]) {
                res[i].push_back(p);
            }
        }

        return res;
    }
};