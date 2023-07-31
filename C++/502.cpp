#include <leetcode.h>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        using pii = pair<int, int>;
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> q;
        vector<pii> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++) {
            while (curr < n && arr[curr].first <= w) {
                q.push(arr[curr++].second);
            }
            if (!q.empty()) {
                w += q.top();
                q.pop();
            } else {
                break;
            }
        }
        return w;
    }
};