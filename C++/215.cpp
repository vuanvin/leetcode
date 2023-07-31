#include <leetcode.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, n = nums.size();
        k = n - k;
        while (s < n) {
            int l = s, pivot = nums[s];
            for (int h = s + 1; h < n; ++h) {
                if (nums[h] <= pivot) {
                    swap(nums[++l], nums[h]);
                }
            }
            swap(nums[l], nums[s]);
            if (k == l) {
                return nums[k];
            } else if (k < l) {
                n = l;
            } else {
                s = l + 1;
            }
            
        }
        return nums[k];
    }
};