#include <leetcode.h>

class Solution {
public:
    const vector<string> one = {"",    "One",    "Two",    "Three",    "Four",     "Five",    "Six",     "Seven",     "Eight",    "Nine",
                                "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> two = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> three = {"", " Thousand", " Million", " Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<int> digits;
        string ans;
        for (int i = 0; i < 4; i++) {
            int val = num % 1000;
            num /= 1000;
            if (val == 0) continue;
            string temp = "";
            if (val / 100) {
                auto dig = one[val / 100];
                temp += dig;
                temp += " Hundred";
            }
            val = val - (val / 100 * 100);
            if (val > 0) {
                if (val < 20) {
                    if (!temp.empty()) temp += " ";
                    temp += one[val];
                } else {
                    if (!temp.empty()) temp += " ";
                    temp += two[val / 10];
                    val %= 10;
                    if (val) {
                        if (!temp.empty()) temp += " ";
                        temp += one[val];
                    }
                }
            }
            temp += three[i];
            if (ans.empty()) {
                ans = temp + ans;
            } else {
                ans = temp + " " + ans;
            }
        }
        return ans;
    }
};