#include <leetcode.h>

class Solution {
public:
    string frequencySort(string s) {
        string ans;
        map<char, int> mp;
        for (auto c : s) mp[c]++;
        vector<char> v;
        for (auto [c, _] : mp) v.push_back(c);
        sort(v.begin(), v.end(), [&](char x, char y) { return mp[x] > mp[y]; });
        for (auto c : v) ans += string(mp[c], c);
        return ans;
    }
};