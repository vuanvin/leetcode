#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<pair<int, int>> stk;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto h = heights[i];
        int nextH = (i + 1 < n) ? heights[i+1] : INT_MIN;
        ans = max(ans, h);
        for (int j = stk.size() - 1; j >= 0; j--) {
            auto p = stk[j];
            if (p.second <= nextH) {
                break;
            }
            ans = max(ans, (i - p.first + 1) * min(h, p.second));
        }

        // pop
        int pos = i;
        while (!stk.empty() && stk.back().second >= h) {
            pos = stk.back().first;
            stk.pop_back();
        }
        stk.push_back({pos, h});
    }

    return ans;
}