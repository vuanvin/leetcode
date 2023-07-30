#include <leetcode.h>

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (auto v : nums) st.insert(v);
        unordered_map<int, int> mp;
        mp[nums[0]]++;
        int r = 1, n = nums.size();
        int cnt = 1, ans = 0;

        for (int l = 0; l < nums.size(); l++) {
            while (r < n && cnt < st.size()) {
                mp[nums[r]]++;
                if (mp[nums[r]] == 1) {
                    cnt++;
                }
                r++;
            }
            if (cnt == st.size()) {
                ans += (n - r + 1);
            }
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) cnt--;
        }
        return ans;
    }
};