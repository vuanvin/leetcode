#include <leetcode.h>

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (const auto& ob : obstacles) {
            mp.emplace(ob[0] * 60001 + ob[1]);
        }
        int ans = 0;
        for (auto T : commands) {
            if (T < 0) {
                d += (T == -1) ? 1 : -1;
                (d += 4) %= 4;
            } else {
                while (T--) {
                    if (mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) break;
                    px += dirs[d][0];
                    py += dirs[d][1];
                    ans = max(ans, px * px + py * py);
                }
            }
        }
        return ans;
    }
};