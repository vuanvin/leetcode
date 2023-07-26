#include <leetcode.h>

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if (expression.size() <= 2) {
            int num = 0;
            for (auto ch : expression) {
                (num *= 10) += ch - '0';
            }
            return {num};
        }
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            if (!isdigit(expression[i])) {
                auto lhs = diffWaysToCompute(expression.substr(0, i));
                auto rhs = diffWaysToCompute(expression.substr(i + 1));
                for (auto l : lhs) {
                    for (auto r : rhs) {
                        if (expression[i] == '+') {
                            ans.push_back(l + r);
                        } else if (expression[i] == '-') {
                            ans.push_back(l - r);
                        } else if (expression[i] == '*') {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }
        return ans;
    }
};