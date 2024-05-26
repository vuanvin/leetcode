#include <leetcode.h>

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        if (n <= indexDifference) {
            return {-1, -1};
        }

        vector<int> A, B, C, D;
        A.reserve(n); A.push_back(0);
        B.reserve(n); B.push_back(n - 1);
        C.reserve(n); C.push_back(0);
        D.reserve(n); D.push_back(n - 1);

        for (int i = 1; i < n - indexDifference; i++) {
            if (nums[i] < nums[A.back()]) {
                A.push_back(i);
            } else if (nums[i] > nums[C.back()]) {
                C.push_back(i);
            }
        }
        for (int i = n - 2; i >= indexDifference; i--) {
            if (nums[i] > nums[B.back()]) {
                B.push_back(i);
            } else if (nums[i] < nums[D.back()]) {
                D.push_back(i);
            }
        }

        for (auto a : A) {
            while (!B.empty() && B.back() - a < indexDifference) {
                B.pop_back();
            }
            if (!B.empty()) {
                int b = B.back();
                if (nums[b] - nums[a] >= valueDifference) {
                    return {a, b};
                }
            }
        }

        for (auto c : C) {
            while (!D.empty() && D.back() - c < indexDifference) {
                D.pop_back();
            }
            if (!D.empty()) {
                int d = D.back();
                if (nums[c] - nums[d] >= valueDifference) {
                    return {c, d};
                }
            }
        }
        return {-1, -1};
    }
};