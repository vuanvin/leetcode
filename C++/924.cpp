#include <leetcode.h>

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> flags(n, -1);
        unordered_map<int, int> cnt_map;

        for (auto ini : initial) {
            flags[ini] = -2;
        }

        for (auto ini : initial) {
            if (flags[ini] >= 0) {
                continue;
            }

            queue<int> Q;
            Q.push(ini);
            flags[ini] = ini;
            int cnt = 1;

            while (!Q.empty()) {
                auto p = Q.front();
                Q.pop();

                for (int q = 0; q < n; q++) {
                    if (graph[p][q] == 1 && flags[q] < 0) {
                        if (flags[q] == -2) {
                            cnt_map[ini] = 0;
                        }

                        flags[q] = ini;
                        Q.push(q);
                        cnt++;
                    }
                }
            }

            if (!cnt_map.count(ini)) {
                cnt_map[ini] = cnt;
            }
        }

        int ans = initial[0], mx = INT_MIN;

        for (auto ini : initial) {
            if (cnt_map[flags[ini]] > mx) {
                ans = ini;
                mx = cnt_map[flags[ini]];
            } else if (cnt_map[flags[ini]] == mx) {
                ans = min(ans, ini);
            }
        }

        return ans;
    }
};