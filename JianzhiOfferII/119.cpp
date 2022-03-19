#include <bits/stdc++.h>
using namespace std;

int longestConsecutive_1(vector<int>& nums) {
    int maxn = 1000;
    vector<unordered_set<int>> rs(maxn, unordered_set<int>());

    for (auto num : nums) {
        auto pos = ((num % maxn) + maxn) % maxn;
        rs[pos].insert(num);
    }

    int n = nums.size();
    int start = 0;
    int ans = 0;
    while (true) {
        while (rs[start].empty()) {
            start++;
            if (start == n) break;
        }

        auto it = rs[start].begin();
        int num = *it;
        rs[start].erase(it);
        int cnt = 1;

        // back
        for (int i = num - 1; ; i--) {
            auto pos = ((i % maxn) + maxn) % maxn;
            it = rs[pos].find(i);
            if (it != rs[pos].end()) {
                rs[pos].erase(it);
                cnt++;
            } else {
                break;
            }
        }

        // forward
        for (int i = num + 1; ; i++) {
            auto pos = ((i % maxn) + maxn) % maxn;
            it = rs[pos].find(i);
            if (it != rs[pos].end()) {
                rs[pos].erase(it);
                cnt++;
            } else {
                break;
            }
        }

        ans = max(ans, cnt);
    }

    return ans;
}

int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> S;
    for (auto num : nums) {
        S.insert(num);
    }

    for (auto num : S) {
        if (!S.count(num - 1)) {
            int cnt = 1;
            int n = num + 1;
            while (S.count(n)) { n++; cnt++; }
            ans = max(ans, cnt);
        }
    }

    return ans;
}