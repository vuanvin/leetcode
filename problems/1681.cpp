#include <leetcode.h>

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        auto n = nums.size();
        auto gsize = n / k;
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        auto term = (1 << n) - 1;

        unordered_map<int, int> values;
        for (int mask = 1; mask <= term; ++mask) {
            if (__builtin_popcount(mask) != gsize) {
                continue;
            }
            int mn = 20, mx = 0;
            unordered_set<int> take;
            for (int i = 0; i < n; ++i) {
                auto val = nums[i];
                if (mask & (1 << i)) {
                    if (take.count(val) > 0) {
                        break;
                    }
                    take.insert(val);
                    mn = min(mn, val);
                    mx = max(mx, val);
                }
            }
            if (take.size() == gsize) {
                values[mask] = mx - mn;
            }
        }

        for (int mask = 0; mask <= term; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            unordered_map<int, int> prop;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    prop[nums[i]] = i;
                }
            }
            if (prop.size() < gsize) continue;
            int supp = 0;
            for (auto p : prop) {
                supp |= (1 << p.second);
            }

            auto next = supp;
            while (next > 0) {
                if (values.count(next) > 0) {  // satisfy the condition
                    dp[mask | next] = min(dp[mask | next], dp[mask] + values[next]);
                }
                next = (next - 1) & supp;
            }
        }

        return (dp[term] < INT_MAX) ? dp[term] : -1;
    }
};