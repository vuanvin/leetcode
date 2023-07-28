#include <leetcode.h>

class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int ln = 0, rn = 0;
        for (char c : s) {
            if (c == '(') {
                ln++;
            } else if (c == ')') {
                if (ln == 0) {
                    rn++;
                } else {
                    ln--;
                }
            }
        }
        dfs(s, 0, ln, rn);
        return ans;
    }

    bool valid(const string& s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                if (cnt == 0) {
                    return false;
                } else {
                    cnt--;
                }
            }
        }
        return cnt == 0;
    }

    void dfs(string s, int i, int ln, int rn) {
        if (ln == 0 && rn == 0 && valid(s)) {
            ans.push_back(s);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (j != i && s[j] == s[j - 1]) continue;
            if (ln + rn > s.size() - j) return;
            if (ln > 0 && s[j] == '(') dfs(s.substr(0, j) + s.substr(j + 1), j, ln - 1, rn);
            if (rn > 0 && s[j] == ')') dfs(s.substr(0, j) + s.substr(j + 1), j, ln, rn - 1);
        }
    }
};