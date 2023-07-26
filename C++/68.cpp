#include <leetcode.h>

class Solution {
public:
    string blank(int n) { return string(n, ' '); }
    string join(const vector<string>& words, int l, int r, string sep) {
        string s = words[l];
        for (int i = l + 1; i < r; ++i) {
            s += sep + words[i];
        }
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int r = 0, n = words.size();

        while (true) {
            int l = r;
            int len = 0;
            while (r < n && len + words[r].size() + r - l <= maxWidth) {
                len += words[r++].size();
            }
            if (r == n) {
                auto s = join(words, l, r, " ");
                ans.emplace_back(s + blank(maxWidth - s.size()));
                return ans;
            }

            int nw = r - l;
            int ns = maxWidth - len;
            if (nw == 1) {
                ans.emplace_back(words[l] + blank(ns));
                continue;
            }

            int avg = ns / (nw - 1);
            int ext = ns % (nw - 1);
            auto s1 = join(words, l, l + ext + 1, blank(avg + 1));
            auto s2 = join(words, l + ext + 1, r, blank(avg));
            ans.emplace_back(s1 + blank(avg) + s2);
        }
    }
};