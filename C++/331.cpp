#include <leetcode.h>

class Solution {
    bool res;

public:
    int dfs(vector<bool>& s, int i) {
        if (s[i] == false || i + 1 >= s.size()) {
            res = false;
            return i + 2;
        }
        int j;
        if (s[i + 1] == false) {
            j = i + 2;
        } else {
            j = dfs(s, i + 1);
        }

        if (j >= s.size()) {
            res = false;
            return j + 1;
        } else if (s[j] == false) {
            return j + 1;
        } else {
            return dfs(s, j);
        }
    }
    bool isValidSerialization(string preorder) {
        int n = 1, k = 0;
        for (auto ch : preorder) {
            if (ch == ',') n++;
        }
        vector<bool> s(n, false);
        s[k++] = preorder[0] != '#';
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') {
                s[k++] = preorder[i + 1] != '#';
            }
        }

        res = true;
        if (s.size() == 1) {
            return s[0] == false;
        }
        int j = dfs(s, 0);
        return res && j == s.size();
    }
};