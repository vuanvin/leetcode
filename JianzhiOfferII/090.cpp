#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> a(2, 0);
        vector<int> b(2, 0);

        a[1] = nums[0];
        for (int i = 1; i < n-1; i++) {
            b[0] = max(a[0], a[1]);
            b[1] = a[0] + nums[i];

            a[0] = b[0];
            a[1] = b[1];
        }
        ans = max(a[0], a[1]);

        a[0] = a[1] = 0;
        for (int i = 1; i < n; i++) {
            b[0] = max(a[0], a[1]);
            b[1] = a[0] + nums[i];

            a[0] = b[0];
            a[1] = b[1];
        }

        ans = max(max(a[0], a[1]), ans);

        return ans;
    }
};