#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(2, 0);
        vector<int> b(2, 0);
        a[1] = nums[0];

        for (int i = 1; i < n; i++) {
            b[0] = max(a[0], a[1]);
            b[1] = a[0] + nums[i];

            a[0] = b[0];
            a[1] = b[1];
        }

        return max(a[0], a[1]);
    }
};