#include <leetcode.h>

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
                customers[i] = 0;
            }
        }

        int tot = accumulate(customers.begin(), customers.begin() + minutes, 0);
        int mx = tot;
        for (int i = minutes; i < n; i++) {
            tot = tot + customers[i] - customers[i - minutes];
            mx = max(mx, tot);
        }

        return ans + mx;
    }
};