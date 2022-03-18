#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int j = 0;
    int n = s.size();
    int exceed = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto ch = s[i];
        if (mp.count(ch)) {
            mp[ch]++;
            if (mp[ch] == 2) {
                exceed++;
            }
            while (exceed > 0) {
                mp[s[j]]--;
                if (mp[s[j]] == 1) {
                    exceed--;
                }
                j++;
            }
        } else {
            mp[ch] = 1;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}