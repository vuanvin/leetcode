#include <leetcode.h>

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;

        while (mainTank >= 5) {
            int quo = mainTank / 5, res = mainTank % 5;
            ans += quo * 5;

            int add = min(additionalTank, quo);
            mainTank = res + add;
            additionalTank -= add;
        }

        return (ans + mainTank) * 10;
    }
};