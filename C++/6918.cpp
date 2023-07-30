#include <leetcode.h>

class Solution {
public:
    vector<string> res;
    string concate(const string& a, const string& b) {
        int m = a.size(), n = b.size();
        int i = 0;
        if (a.find(b) != string::npos) return a;
        if (b.find(a) != string::npos) return b;
        for (; i < m; i++) {
            if (a.substr(i) == b.substr(0, m - i)) {
                break;
            }
        }
        auto ret = a + b.substr(m - i);
        return ret;
    }

    void dfs(int pos, string a, string b, string c) {
        if (pos == 0) {
            dfs(1, b, a, c);
            dfs(1, c, b, a);
            dfs(1, a, b, c);
        } else if (pos == 1) {
            dfs(2, a, b, c);
            dfs(2, a, c, b);
        } else {
            res.push_back(concate(concate(a, b), c));
        }
    }

    string minimumString(string a, string b, string c) {
        dfs(0, a, b, c);
        sort(res.begin(), res.end(), [](string& x, string& y) { return x.size() != y.size() ? x.size() < y.size() : x < y; });
        return res[0];
    }
};