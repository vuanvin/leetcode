#include <leetcode.h>

class Solution {
public:
    vector<int> deal(const vector<int>& nums, int k) {
        vector<int> v;
        auto remain = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            auto val = nums[i];
            while (!v.empty() && remain > k && v.back() < val) {
                v.pop_back();
                remain--;
            }
            if (v.size() < k) {
                v.push_back(val);
            } else {
                remain--;
            }
        }
        return v;
    }

    bool compare(vector<int>& v1, int i1, vector<int>& v2, int i2) {
        for (; i1 < v1.size() && i2 < v2.size(); i1++, i2++) {
            if (v1[i1] != v2[i2]) {
                return v1[i1] < v2[i2];
            }
        }
        return v1.size() == i1;
    }

    vector<int> merge(vector<int> v1, vector<int> v2) {
        int n1 = v1.size(), n2 = v2.size();
        if (n1 == 0) return v2;
        if (n2 == 0) return v1;
        vector<int> v(n1 + n2);
        int i1 = 0, i2 = 0;
        for (int i = 0; i < v.size(); i++) {
            if (compare(v1, i1, v2, i2)) {
                v[i] = v2[i2++];
            } else {
                v[i] = v1[i1++];
            }
        }
        return v;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans(k, 0);
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            auto v1 = deal(nums1, i);
            auto v2 = deal(nums2, k - i);
            auto v = merge(v1, v2);
            if (compare(ans, 0, v, 0)) {
                ans.swap(v);
            }
        }
        return ans;
    }
};