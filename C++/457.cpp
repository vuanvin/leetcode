#include <leetcode.h>

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int bound = 1000 + 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < bound) {
                int curr_bound = bound + i;
                int j = i;
                bool is_ok = true;
                while (nums[j] < bound) {
                    int v = nums[j];
                    int nxt = (j + v + (abs(v) / n + 1) * n) % n;
                    nums[j] = curr_bound;
                    if (nxt == j || (nums[nxt] != curr_bound && (nums[nxt] < 0) ^ (v < 0))) {
                        is_ok = false;
                        break;
                    }
                    j = nxt;
                }
                if (is_ok && nums[j] == curr_bound) return true;
            }
        }
        return false;
    }
};