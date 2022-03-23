#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<vector<int>> ans;
        vector<int> sample = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); i++) {
            auto iv = intervals[i];
            if (iv[0] > sample[1]) {
                ans.emplace_back(sample);
                sample[0] = iv[0];
                sample[1] = iv[1];
            } else {
                sample[1] = max(sample[1], iv[1]);
            }
        }

        ans.emplace_back(sample);

        return ans;
    }
};