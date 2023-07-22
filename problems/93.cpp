#include <leetcode.h>

class Solution {
private:
    vector<string> ans;
    vector<int> segments;

public:
    void dfs(const string& s, int seg, int pos) {
        if (seg == 4 && pos == s.size()) {
            string addr;
            for (int i = 0; i < 4; ++i) {
                addr += to_string(segments[i]);
                if (i != 3) {
                    addr += ".";
                }
            }
            ans.push_back(addr);
            return;
        }

        if (pos == s.size() || seg == 4) {
            return;
        }

        if (s[pos] == '0') {
            segments[seg] = 0;
            dfs(s, seg + 1, pos + 1);
        } else {
            int addr = 0;
            for (int i = pos; i < s.size(); ++i) {
                (addr *= 10) += (s[i] - '0');
                if (addr <= 0xFF) {
                    segments[seg] = addr;
                    dfs(s, seg + 1, i + 1);
                } else {
                    break;
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        segments.resize(4);
        dfs(s, 0, 0);
        return ans;
    }
};