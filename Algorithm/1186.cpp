#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp0 = arr[0], dp1 = 0, ans = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(dp0, 0) + arr[i];
            ans = max(ans, max(dp0, dp1));
        }
        return ans;
    }
};