#include <leetcode.h>

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        vector<string> ans;
        string expr;
        function<void(int, long, long)> dfs = [&](int i, long res, long mul) -> void {
            if (i == n) {
                if (res == target) {
                    ans.push_back(expr);
                }
                return;
            }
            int sz = expr.size();
            if (i > 0) {
                expr.push_back('_');
            }
            long val = 0;
            for (int j = i; j < n && (j == i || num[i] != '0'); j++) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) {
                    dfs(j + 1, val, val);
                } else {
                    expr[sz] = '+';
                    dfs(j + 1, res + val, val);
                    expr[sz] = '-';
                    dfs(j + 1, res - val, -val);
                    expr[sz] = '*';
                    dfs(j + 1, res - mul + mul * val, mul * val);
                }
            }
            expr.resize(sz);
        };
        dfs(0, 0, 0);
        return ans;
    }
};