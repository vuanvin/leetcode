#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ord;
        for (const auto& ch : t) {
            ord[ch]++;
        }

        auto n_ok = ord.size();
        int l = 0;
        int ansl = 0, ansr = numeric_limits<int>::max();

        for (int r = 0; r < s.size(); r++) {
            const auto& rch = s[r];

            if (ord.count(rch)) {
                ord[rch]--;
                if (ord[rch] == 0) { n_ok--; }

                if (n_ok == 0) {
                    while (l <= r) {
                        const auto& lch = s[l++];
                        if (ord.count(lch)) {
                            ord[lch]++;
                            if (ord[lch] == 1) {
                                n_ok++;
                                if (ansr - ansl > r - l + 1) { ansl = l - 1; ansr = r; }
                                break;
                            }
                        }
                    }
                }
            }
        }

        return (ansr == numeric_limits<int>::max()) ? "" : s.substr(ansl, ansr - ansl + 1);
    }
};