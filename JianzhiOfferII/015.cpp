#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int len = 26;
    auto & s1 = p;
    auto & s2 = s;
    int m = s1.size(), n = s2.size();

    vector<int> res;
    if (m > n) return res;

    vector<int> cnt(len, 0);
    int pos = 0, neg = 0;
    for (int i = 0; i < m; i++) {
        cnt[s1[i] - 'a'] ++;
        if (cnt[s1[i] - 'a'] == 1) pos++;
    }

    int i = 0, j = 0;
    for ( ; i < n; i++) {
        cnt[s2[i] - 'a']--;
        if (cnt[s2[i] - 'a'] == 0) {
            pos--;
        } else if (cnt[s2[i] - 'a'] == -1) {
            neg++;
        }

        if (pos == 0) {
            if (neg == 0) { res.push_back(j); }
            else {
                while (j <= i && neg > 0) {
                    cnt[s2[j] - 'a']++;

                    if (cnt[s2[j] - 'a'] == 1) {
                        pos++;
                    } else if (cnt[s2[j] - 'a'] == 0) {
                        neg--;
                    }

                    j++;
                }
                if (pos == 0) res.push_back(j);
            }
        }
    }

    return res;
}