#include <leetcode.h>

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n != 0) return -1;
        int avg = total / n;
        int ans = 0, s = 0;
        for (auto v : machines) {
            v -= avg;
            s += v;
            ans = max(max(ans, abs(s)), v);
        }
        return ans;
    }
};