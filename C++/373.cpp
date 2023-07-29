#include <leetcode.h>

class Solution {
public:
    bool compare(vector<int>& nums1, int i1, int add1, vector<int>& nums2, int i2, int add2) {
        int n1 = nums1.size(), n2 = nums2.size();
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] + add1 != nums2[i2] + add2) {
                return nums1[i1] + add1 < nums2[i2] + add2;
            }
        }
        return n1 == i1;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int i1 = 0, i2 = 0;
        while (k < 0) {
            
        }
    }
};