#include <leetcode.h>

class Solution {
public:
    static constexpr int mod = 1337;
    int superPow(int a, vector<int>& b) {
        a = a % mod;
        int ans = 1;
        for (int i = 0; i < b.size(); i++) {
            ans = (ans * ans) % mod;
            int tmp = ans;
            ans = (ans * ans) % mod;
            ans = (ans * ans) % mod;
            ans = (tmp * ans) % mod;
            int e = b[i];
            int p = a;
            while (e) {
                if (e % 2) ans = (ans * p) % mod;
                p = (p * p) % mod;
                e /= 2;
            }
        }
        return ans;
    }
};