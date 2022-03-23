#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> UM;

        for (auto & str : strs) {
            auto key = str;
            sort(key.begin(), key.end());
            if (UM.count(key)) {
                UM[key].push_back(str);
            } else {
                UM[key] = {str};
            }
        }

        vector<vector<string>> ans;
        for (auto item : UM) {
            ans.push_back(item.second);
        }

        return ans;
    }
};