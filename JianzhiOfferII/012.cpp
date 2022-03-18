#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (auto & num : nums) {
        sum += num;
    }

    sum -= nums[0];
    if (sum == 0) return 0;

    int left = 0;
    for (int i = 1; i < n; i++) {
        sum -= nums[i];
        left += nums[i-1];
        if (sum == left) {
            return i;
        }
    }
    return -1;
}