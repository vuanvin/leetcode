#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
         if (s[i] != s[j]) break;
         i++; j--;
    }
    int x = i++, y = j-1;
    bool res = true;
    while (i < j) {
        if (s[i] != s[j]) {
            res = false; break;
        }
        i++; j--;
    }
    if (res) return true;

    while (x < y) {
        if (s[x] != s[y]) {
            return false;
        }
        x++; y--;
    }
    return true;
}