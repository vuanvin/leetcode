// https://leetcode.cn/problems/deep-dark-fraction/
#include <leetcode.h>

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int len = cont.size();
        int m = 1, n = cont[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            int a = cont[i];
            swap(m, n);
            n += a * m;
            int g = gcd(m, n);
            n /= g;
            m /= g;
        }
        return {n, m};
    }
};