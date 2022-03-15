#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int base = min('a', 'A');
    int maxn = max('z', 'Z') - base + 1;
    vector<int> cnt(maxn, 0);

    for (auto c : t) {
        cnt[c - base] ++;
    }

    int success = 0;
    int n = s.size();
    int left = 0, len  = INT_MAX;

    for (int i = 0; i < maxn; i++) {
        if (cnt[i] == 0) success ++;
    }

    int i, j = 0;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        cnt[ch - base] --;
        if (cnt[ch - base] == 0) success ++;

        if (success == maxn) {
            if (i - j + 1 < len) { len = i - j + 1; left = j; }

            while (j < i) {
                char ch = s[j++];
                cnt[ch - base] ++;
                if (cnt[ch - base] == 1) {
                    success --;
                    break;
                } else {
                    if (i - j + 1 < len) {
                        len = i - j + 1;
                        left = j;
                    }
                }
            } 
        }
    }

    if (len != INT_MAX) return s.substr(left, len);
    return string();
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
}