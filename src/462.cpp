#include <leetcode.h>

class Solution {
public:
    int getMedian(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2, s = 0;
        while (s < n) {
            int l = s, pivot = nums[s];
            for (int h = s + 1; h < n; ++h) {
                if (nums[h] <= pivot) {
                    swap(nums[++l], nums[h]);
                }
            }
            swap(nums[l], nums[s]);
            if (mid == l) {
                return nums[mid];
            } else if (mid < l) {
                n = l;
            } else {
                s = l + 1;
            }
            
        }
        return nums[mid];
    }

    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        auto median = getMedian(nums);
        for (auto v : nums) {
            ans += abs(median - v);
        }
        return ans;
    }
};