#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int j = 0;
    int n = nums.size();

    int prod = 1;
    int res = 0;

    for (int i = 1; i <= n; i++) {
        prod *= nums[i-1];
        while (j < i && prod >= k) {
            prod /= nums[j++];
        } 
        res += i - j;
    }

    return res;
}