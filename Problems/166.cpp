#include <leetcode.h>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator, den = denominator;
        int sign = 1;
        if (num == 0) return "0";
        if (num < 0) {
            sign *= -1;
            num = -num;
        }
        if (den < 0) {
            sign *= -1;
            den = -den;
        }
        string ans = to_string(num / den);
        num %= den;
        if (num != 0) {
            ans.push_back('.');
            unordered_map<int, int> uniq;
            while (num && !uniq.count(num)) {
                uniq.insert({num, ans.size()});
                num *= 10;
                ans.push_back(num / den + '0');
                num %= den;
            }
            if (num) {
                ans.insert(uniq[num], 1, '(');
                ans.push_back(')');
            }
        }

        if (sign < 0) {
            ans = "-" + ans;
        }
        return ans;
    }
};