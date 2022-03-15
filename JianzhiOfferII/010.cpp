#include <bits/stdc++.h>
using namespace std;

int subarraySum_1(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) {
                ans ++;
            }
        }
    }

    return ans;
}

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int target = sum - k;
        if (cnt.count(target)) ans += cnt[target];
        if (cnt.count(sum)) {
            cnt[sum] += 1;
        } else {
            cnt[sum] = 1;
        }
    }
    return ans;
}

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    vector<pair<int, int>> hello;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == k) ans ++;
        hello.push_back(pair<int, int>(sum, i));
    }

    sort(hello.begin(), hello.end(), [](pair<int, int>a, pair<int, int>b) { return a.first <= b.first; });

    int j = 1;
    for (int i = 0; i < n; i++) {
        int a = hello[i].first;
        int ak = hello[i].second;

        int b = hello[j].first;
        int bk = hello[j].second;

        while (b - a <= k) {
            if (bk > ak && b - a == k) {
                ans ++;
            }

            j ++;
            if (j >= n) break;
            int b = hello[j].first;
            int bk = hello[j].second;
        }
    }

    return ans;
}