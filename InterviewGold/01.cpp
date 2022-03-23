#include <bits/stdc++.h>
using namespace std;

bool isUnique(string astr) {
    int bitMask = 0;

    for (auto ch : astr) {
        if (bitMask & (1 << (ch - 'a'))) return false;
        bitMask |= (1 << (ch - 'a'));
    }

    return true;
}