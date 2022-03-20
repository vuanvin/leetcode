#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> totals(3, 0);

        for (int i = 2; i < cost.size(); i++) {
            totals[2] = min(totals[0] + cost[i-2], totals[1] + cost[i-1]);
            totals[0] = totals[1];
            totals[1] = totals[2];
        }

        return totals[2];
    }
};