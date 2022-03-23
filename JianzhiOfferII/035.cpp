#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i = 0; i < n; i++) {
            minutes[i] = 60 * stoi(timePoints[i].substr(0, 2));
            minutes[i] += stoi(timePoints[i].substr(3, 2));
        }

        int zero = 24 * 60;
        sort(minutes.begin(), minutes.end());

        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            ans = min(ans, minutes[i] - minutes[i-1]);
        }

        ans = min(ans, zero - minutes[n-1] + minutes[0]);
        return ans;
    }
};