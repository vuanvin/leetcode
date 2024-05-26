#include <leetcode.h>

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) {
            return {};
        }
        sort(changed.begin(), changed.end());
        unordered_map<int, int> um;
        for (auto ch : changed) {
            um[ch]++;
        }
        vector<int> res;
        for (auto ch : changed) {
            if (um[ch] > 0) {
                if (um[ch * 2] > 0) {
                    um[ch]--;
                    um[ch * 2]--;
                    res.push_back(ch);
                } else {
                    return {};
                }
            }
        }
        return res;
    }
};