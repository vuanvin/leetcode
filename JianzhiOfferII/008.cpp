#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0;
    int n = nums.size();

    int sum = 0;
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= target) {
            res = min(i - j + 1, res);
            sum -= nums[j++];
        }
    }

    return res == INT_MAX ? 0 : res;
}