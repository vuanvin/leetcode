#include <leetcode.h>

class Solution {
public:
    string finalString(string s) {
        std::deque<char> q;
        bool r = false;
        for (auto ch : s) {
            if (ch == 'i') {
                r = !r;
            } else {
                if (r) {
                    q.push_front(ch);
                } else {
                    q.push_back(ch);
                }
            }
        }
        if (r) reverse(q.begin(), q.end());
        return string(q.begin(), q.end());
    }

    // string finalString(string s) {
    //     int n = s.size();
    //     int k = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (s[i] == 'i') {
    //             reverse(s.begin(), s.begin() + k);
    //         } else {
    //             s[k++] = s[i];
    //         }
    //     }
    //     return s.substr(0, k);
    // }
};