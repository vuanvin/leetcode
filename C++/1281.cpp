#include <leetcode.h>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod, sum;
        while (n) {
            prod *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return prod - sum;
    }
};