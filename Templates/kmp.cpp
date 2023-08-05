#include <bits/stdc++.h>
using namespace std;

int kmp(string s, string p) {
    int m = s.size(), n = p.size();
    vector<int> next(n);
    next[0] = -1;
    for (int l = 0, r = 1; r < p.size(); l++, r++) {
        next[r] = l;
        if (p[l] == p[r]) {
            while ((next[r] = next[next[r]]) >= 0 && p[next[r]] == p[r]) {
            }
        } else {
            while ((l = next[l]) >= 0 && p[l] != p[r]) {
            }
        }
    }
    int i, j;
    for (i = 0, j = 0; i < m; i++) {
        while (j >= 0 && p[j] != s[i]) {
            j = next[j];
        }
        j += 1;
        if (j == n) break;
    }
    return i - j + 1;
}

int kmp2(string s, string p) {
    int m = s.size(), n = p.size();
    vector<int> fail(n, -1);
    for (int i = 1; i < n; i++) {
        int j = fail[i - 1];
        while (j != -1 && p[j + 1] != p[i]) {
            j = fail[j];
        }
        if (p[j + 1] == p[i]) {
            fail[i] = j + 1;
        }
    }
    int i, j;
    for (i = 0, j = -1; i < m; i++) {
        while (j != -1 && p[j + 1] != s[i]) {
            j = fail[j];
        }
        if (p[j + 1] == s[i]) j++;
        if (j == n - 1) break;
    }
    return i - j;
}

int main() {
    string text =
        "aabbdabcaa"
        "aabbdabcaa"
        "aaaabcxdax";
    string pattern = "aabc";  // res = 22

    cout << kmp(text, pattern) << endl;
    cout << kmp2(text, pattern) << endl;
}