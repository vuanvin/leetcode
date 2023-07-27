#include <leetcode.h>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);
        if (words.size() != pattern.size()) return false;
        unordered_map<char, string> ps;
        for (int i = 0; i < words.size(); ++i) {
            if (ps.count(pattern[i])) {
                if (words[i] != ps[pattern[i]]) return false;
            } else {
                ps[pattern[i]] = words[i];
            }
        }
        unordered_set<string> uniq;
        for (auto [_, s] : ps) {
            if (uniq.count(s)) return false;
            uniq.insert(s);
        }
        return true;
    }
};