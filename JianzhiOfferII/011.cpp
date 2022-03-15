#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int high = 0, low = 1;
    int cnt = 0, ans = 0;
    unordered_map<int, int> map;

    map[0] = -1;

    for (int i = 0; i < n; i++) {
        cnt += nums[i] == 1 ? 1 : -1;
        if (map.count(cnt)) {
            ans = max(ans, i - map[cnt]);
        } else {
            map[cnt] = i;
        }
    }

    return ans;
}