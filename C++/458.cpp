#include <leetcode.h>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie;
        return ceil(log2l(buckets) / log2l(T + 1)); 
    }
};