#include <leetcode.h>

class Solution {
public:
    int encode(const string& s, int pos) {
        int num = 0;
        for (int i = pos; i < pos + 10; ++i) {
            auto ch = s[i];
            num <<= 2;
            if (ch == 'A') {
                num |= 0;
            } else if (ch == 'C') {
                num |= 1;
            } else if (ch == 'G') {
                num |= 2;
            } else {
                num |= 3;
            }
        }
        return num;
    }
    string decode(int val) {
        string str;
        for (int i = 0; i < 10; ++i) {
            auto ch = val & 3;
            if (ch == 0) {
                str += 'A';
            } else if (ch == 1) {
                str += 'C';
            } else if (ch == 2) {
                str += 'G';
            } else {
                str += 'T';
            }
            val >>= 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> dna;
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i <= n - 10; ++i) {
            dna[encode(s, i)]++;
        }
        for (auto d : dna) {
            if (d.second > 1) {
                ans.push_back(decode(d.first));
            }
        }
        return ans;
    }
};