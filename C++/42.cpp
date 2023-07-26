#include <leetcode.h>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n - 1;
        int hl = height[l], hr = height[r];
        while (l < r - 1) {
            if (hl <= hr) {
                if (height[++l] < hl) {
                    ans += hl - height[l];
                } else {
                    hl = height[l];
                }
            } else {
                if (height[--r] < hr) {
                    ans += hr - height[r];
                } else {
                    hr = height[r];
                }
            }
        }
        return ans;
    }
};