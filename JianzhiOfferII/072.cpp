#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;

        for (int base = 1 << 15; base; base >>= 1) {
            unsigned num = ans | base;
            if (num * num <= x) {
                ans = num;
            }
        }

        return ans;
    }
};