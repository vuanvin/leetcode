#include <leetcode.h>

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), k = sources.size();
        vector<int> ops(k);
        iota(ops.begin(), ops.end(), 0);
        sort(ops.begin(), ops.end(), [&](int i, int j) { return indices[i] < indices[j]; });

        string ans;
        int p = 0;
        for (int i = 0; i < n;) {
            while (p < k && indices[ops[p]] < i) ++p;
            bool succeed = false;
            while (p < k && indices[ops[p]] == i) {
                if (s.substr(i, sources[ops[p]].size()) == sources[ops[p]]) {
                    succeed = true;
                    break;
                }
                ++p;
            }
            if (succeed) {
                ans += targets[ops[p]];
                i += sources[ops[p]].size();
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};