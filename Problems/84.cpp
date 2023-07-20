#include <leetcode.h>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> area(heights);
        vector<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int pos = i;
            while (!st.empty() && st.back().first >= heights[i]) {
                pos = st.back().second;
                st.pop_back();
            }
            area[i] += (i - pos) * heights[i];
            st.emplace_back(heights[i], pos);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            int pos = i;
            while (!st.empty() && st.back().first >= heights[i]) {
                pos = st.back().second;
                st.pop_back();
            }
            ans = max(area[i] + (pos - i) * heights[i], ans);
            st.emplace_back(heights[i], pos);
        }
        return ans;
    }
};