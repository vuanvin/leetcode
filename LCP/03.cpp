#include <leetcode.h>

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int xlen = 0, ylen = 0;
        int n = command.size();
        vector<int> command_vec(n);
        command_vec[0] = 0;
        for (auto ch : command) {
            if (ch == 'U') {
                command_vec[xlen + 1] = ++ylen;
            } else {
                ++xlen;
                command_vec[xlen + 1] = ylen;
            }
        }

        int t = min(x / xlen, y / ylen);
        int nx = x - t * xlen, ny = y - t * ylen;

        if (nx > xlen || ny > ylen) return false;
        if (command_vec[nx] > ny || ny > command_vec[nx + 1]) return false;

        for (auto& ob : obstacles) {
            int u = ob[0], v = ob[1];
            if (u > x || v > y) continue;

            int t = min(u / xlen, v / ylen);
            u -= t * xlen;
            v -= t * ylen;

            if (u > xlen || v > ylen) continue;
            if (command_vec[u] <= v && v <= command_vec[u + 1]) return false;
        }

        return true;
    }
};