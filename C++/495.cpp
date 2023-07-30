#include <leetcode.h>

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int fin = -1;
        for (auto t : timeSeries) {
            ans += min(t + duration - 1 - fin, duration);
            fin = t + duration - 1;
        }
        return ans;
    }
};