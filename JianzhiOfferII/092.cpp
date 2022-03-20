#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ans = 0;
        for (auto ch : s) {
            if (ch == '0') {
                ans++;
            }
        }

        int cnt = ans;
        for (auto ch : s) {
            if (ch == '0') {
                cnt--;
            } else {
                cnt++;
            }

            ans = min(ans, cnt);
        }

        return ans;
    }
};