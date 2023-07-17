#include <leetcode.h>

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans(queries.size(), -1);
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& lhs, const vector<int>& rhs) { return lhs[1] - lhs[0] < rhs[1] - rhs[0]; });
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) { return x.first == y.first ? x.second < y.second : x.first < y.first; };
        set<pair<int, int>, decltype(cmp)> qs(cmp);
        for (int i = 0; i < queries.size(); ++i) qs.insert({queries[i], i});
        for (auto& iv : intervals) {
            for (auto it = qs.lower_bound({iv[0], 0}); it != qs.end() && (*it).first <= iv[1]; it = qs.erase(it)) {
                ans[(*it).second] = iv[1] - iv[0] + 1;
            }
        }
        return ans;
    }
};