#include <leetcode.h>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        using pii = pair<int, int>;
        int ans = INT_MIN;
        priority_queue<pii, vector<pii>, less<pii>> heap;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                ans = max(ans, x + y + heap.top().first);
            }
            heap.emplace(y - x, x);
        }
        return ans;
    }
};