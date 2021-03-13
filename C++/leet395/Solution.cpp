//
// Created by YUANYIN on 2021/02/27.
//

#include "../leetcode.h"

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int res = 0;
        for (int t = 1; t <= 26; t++) {
            int l = 0;
            int total = 0;
            int loss = 0;
            vector<int> cnt(26, 0);
            for (int r = 0; r < n; r++) {
                cnt[s[r] - 'a'] ++;

                if (cnt[s[r] - 'a'] == 1) {
                    total ++;
                    loss ++;
                }
                if (cnt[s[r] - 'a'] == k) {
                    loss --;
                }

                while (total > t) {
                    cnt[s[l] - 'a'] --;
                    if (cnt[s[l] - 'a'] == 0) {
                        total --;
                        loss --;
                    }
                    if (cnt[s[l] - 'a'] == k-1) {
                        loss ++;
                    }
                    l ++;
                }

                if (loss == 0) {
                    res = max(res, r - l + 1);
                }
            }
        }

        return res;
    }
};
