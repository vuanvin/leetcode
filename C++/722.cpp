#include <leetcode.h>

class Solution {
public:
    enum State { INIT, SLASH, BLOCK_COMM, BLOCK_STAR };

    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        State state = INIT;

        string line;
        for (auto s : source) {
            for (auto c : s) {
                if (c == '/') {
                    if (state == INIT) {
                        state = SLASH;
                    } else if (state == SLASH) {
                        state = INIT;
                        break;
                    } else if (state == BLOCK_STAR) {
                        state = INIT;
                    }
                } else if (c == '*') {
                    if (state == SLASH) {
                        state = BLOCK_COMM;
                    } else if (state == BLOCK_COMM) {
                        state = BLOCK_STAR;
                    } else if (state == INIT) {
                        line.push_back(c);
                    }
                } else {
                    if (state == SLASH) {
                        line.push_back('/');
                        line.push_back(c);
                        state = INIT;
                    } else if (state == INIT) {
                        line.push_back(c);
                    } else {
                        state = BLOCK_COMM;
                    }
                }
            }

            if (state != BLOCK_COMM) {
                if (state == SLASH) {
                    line.push_back('/');
                }
                if (!line.empty()) {
                    ans.push_back(line);
                }
                line.clear();
                state = INIT;
            }
        }

        if (!line.empty()) {
            ans.push_back(line);
        }

        return ans;
    }
};