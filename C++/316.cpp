#include <leetcode.h>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        map<char, vector<int>> pos;
        for (int i = s.size() - 1; i >= 0; i--) {
            pos[s[i]].push_back(i);
        }
        int n = pos.size();

        for (int i = 0; i < n; i++) {
            auto it = pos.begin();
            auto fr = it->second.back();

            for (; it != pos.end(); ++it) {
                fr = it->second.back();
                auto is_ok = true;
                for (auto& [ch, li]: pos) {
                    if (li.front() < fr) {
                        is_ok = false;
                        break;
                    }
                }
                if (is_ok) break;
            }
            ans.push_back(it->first);
            pos.erase(it);
            for (auto& [ch, li]: pos) {
                while (li.back() < fr) {
                    li.pop_back();
                }
            }
        }
        return ans;
    }
};