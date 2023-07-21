#include <leetcode.h>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money[2] = {0};
        for (auto bill : bills) {
            if (bill == 5) {
                money[0]++;
            } else if (bill == 10) {
                if (money[0] == 0) return false;
                money[1]++;
                money[0]--;
            } else if (bill == 20) {
                bill = 15;
                if (money[1]) {
                    money[1]--;
                    bill -= 10;
                }
                while (money[0] && bill) {
                    money[0]--;
                    bill -= 5;
                }
                if (bill) return false;
            }
        }
        return true;
    }
};