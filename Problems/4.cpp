#include <leetcode.h>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m == 0) {
            return n % 2 == 1 ? nums2[n / 2] : (nums2[n / 2 - 1] + nums2[n / 2]) * 1.0 / 2;
        }

        if (n == 0) {
            return m % 2 == 1 ? nums1[m / 2] : (nums1[m / 2 - 1] + nums1[m / 2]) * 1.0 / 2;
        }

        if ((m + n) % 2 == 1) {
            int mid = (m + n) / 2 - 1;
            int id1 = 0;
            int id2 = 0;

            int who = nums1[0] < nums2[0] ? 0 : 1;
            if (nums1[0] < nums2[0]) {
                id2 = -1;
            } else {
                id1 = -1;
            }

            while (id1 + id2 < mid) {
                if (id1 + 1 == m) {
                    id2++;
                    who = 1;
                } else if (id2 + 1 == n) {
                    id1++;
                    who = 0;
                } else if (nums1[id1 + 1] < nums2[id2 + 1]) {
                    id1++;
                    who = 0;
                } else {
                    id2++;
                    who = 1;
                }
            }

            return who == 0 ? nums1[id1] : nums2[id2];

        } else {
            int mid = (m + n - 1) / 2 - 1;
            int id1 = 0;
            int id2 = 0;

            int who = nums1[0] < nums2[0] ? 0 : 1;
            if (nums1[0] < nums2[0]) {
                id2 = -1;
            } else {
                id1 = -1;
            }

            while (id1 + id2 < mid) {
                if (id1 + 1 == m) {
                    id2++;
                    who = 1;
                } else if (id2 + 1 == n) {
                    id1++;
                    who = 0;
                } else if (nums1[id1 + 1] < nums2[id2 + 1]) {
                    id1++;
                    who = 0;
                } else {
                    id2++;
                    who = 1;
                }
            }

            double res = (who == 0) ? nums1[id1] : nums2[id2];
            if (id1 + 1 == m) {
                id2++;
                who = 1;
            } else if (id2 + 1 == n) {
                id1++;
                who = 0;
            } else if (nums1[id1 + 1] < nums2[id2 + 1]) {
                id1++;
                who = 0;
            } else {
                id2++;
                who = 1;
            }

            res += (who == 0) ? nums1[id1] : nums2[id2];
            return res / 2;
        }
    }
};