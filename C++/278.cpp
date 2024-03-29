#include <leetcode.h>

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (!isBadVersion(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};