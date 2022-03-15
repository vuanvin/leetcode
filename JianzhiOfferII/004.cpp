#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (auto num : nums) {
        int c = b;
        b ^= num & (a | b);
        a ^= num & (~c | a);
    }

    return a;
}