#include <leetcode.h>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int elem[2], vote[2] = {0};
        for (auto v : nums) {
            if (vote[0] > 0 && v == elem[0]) {
                vote[0]++;
            } else if (vote[1] > 0 && v == elem[1]) {
                vote[1]++;
            } else if (vote[0] == 0) {
                vote[0]++;
                elem[0] = v;
            } else if (vote[1] == 0) {
                vote[1]++;
                elem[1] = v;
            } else {
                vote[0]--;
                vote[1]--;
            }
        }
        int cnt[2] = {0};
        for (auto& v : nums) {
            if (vote[0] > 0 && v == elem[0]) {
                cnt[0]++;
            }
            if (vote[1] > 0 && v == elem[1]) {
                cnt[1]++;
            }
        }
        if (vote[0] > 0 && cnt[0] > nums.size() / 3) {
            ans.push_back(elem[0]);
        }
        if (vote[1] > 0 && cnt[1] > nums.size() / 3) {
            ans.push_back(elem[1]);
        }
        return ans;
    }
};