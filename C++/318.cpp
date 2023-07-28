#include <leetcode.h>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bits(n, 0);
        for (int i = 0; i < n; i++) {
            auto word = words[i];
            for (auto ch : word) {
                bits[i] |= 1 << (ch - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(bits[i] & bits[j])) {
                    ans = max(ans, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};