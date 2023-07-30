#include <leetcode.h>

class Solution {
public:
    const int mod = pow(10, 9) + 7;

    long help(string low, string high) {
        int n = low.size();
        vector<unordered_map<char, long>> free(n);
        vector<unordered_map<char, long>> upto(n);
        vector<unordered_map<char, long>> down(n);
        vector<unordered_map<char, long>> just(n);

        if (low[0] == high[0]) {
            just[0][low[0]]++;
        } else {
            upto[0][high[0]]++;
            down[0][low[0]]++;
            for (auto ch = low[0] + 1; ch < high[0]; ++ch) free[0][ch]++;
        }

        for (int i = 1; i < n; i++) {
            for (auto ch = '0'; ch <= '9'; ch++) {
                if (ch - 1 >= '0') free[i][ch] += free[i - 1][ch - 1];
                if (ch + 1 <= '9') free[i][ch] += free[i - 1][ch + 1];
            }
            char ch;
            if (low[i] == high[i]) {
                auto ch = low[i];
                if (ch - 1 >= '0') just[i][ch] += just[i - 1][ch - 1];
                if (ch + 1 <= '9') just[i][ch] += just[i - 1][ch + 1];
            } else {
                ch = high[i];
                if (ch - 1 >= '0') {
                    upto[i][ch] += just[i - 1][ch - 1];
                }
                if (ch + 1 <= '9') {
                    upto[i][ch] += just[i - 1][ch + 1];
                }

                ch = low[i];
                if (ch - 1 >= '0') {
                    down[i][ch] += just[i - 1][ch - 1];
                }
                if (ch + 1 <= '9') {
                    down[i][ch] += just[i - 1][ch + 1];
                }
            }

            ch = high[i];
            if (ch - 1 >= '0') {
                upto[i][ch] += upto[i - 1][ch - 1];
            }
            if (ch + 1 <= '9') {
                upto[i][ch] += upto[i - 1][ch + 1];
            }

            ch = low[i];
            if (ch - 1 >= '0') {
                down[i][ch] += down[i - 1][ch - 1];
            }
            if (ch + 1 <= '9') {
                down[i][ch] += down[i - 1][ch + 1];
            }

            for (auto ch = low[i] + 1; ch < high[i]; ch++) {
                if (ch - 1 >= '0') {
                    free[i][ch] += just[i - 1][ch - 1];
                    free[i][ch] %= mod;
                }
                if (ch + 1 <= '9') {
                    free[i][ch] += just[i - 1][ch + 1];
                    free[i][ch] %= mod;
                }
            }

            for (auto ch = '0'; ch < high[i]; ch++) {
                if (ch - 1 >= '0') {
                    free[i][ch] += upto[i - 1][ch - 1];
                    free[i][ch] %= mod;
                }
                if (ch + 1 <= '9') {
                    free[i][ch] += upto[i - 1][ch + 1];
                    free[i][ch] %= mod;
                }
            }

            for (auto ch = low[i] + 1; ch <= '9'; ch++) {
                if (ch - 1 >= '0') {
                    free[i][ch] += down[i - 1][ch - 1];
                    free[i][ch] %= mod;
                }
                if (ch + 1 <= '9') {
                    free[i][ch] += down[i - 1][ch + 1];
                    free[i][ch] %= mod;
                }
            }
        }

        long res = 0;
        for (auto ch = '0'; ch <= '9'; ch++) {
            res += free[n - 1][ch] + just[n - 1][ch] + down[n - 1][ch] + upto[n - 1][ch];
            res %= mod;
        }

        return res;
    }

    int countSteppingNumbers(string low, string high) {
        int m = low.size(), n = high.size();
        if (m == n) {
            return help(low, high);
        }

        long res = 0;
        res += help(low, string(m, '9'));
        res %= mod;
        res += help("1" + string(n - 1, '0'), high);
        res %= mod;
        for (int i = m + 1; i < n; i++) {
            res += help("1" + string(i - 1, '0'), string(i, '9'));
            res %= mod;
        }
        res %= mod;
        return res;
    }
};