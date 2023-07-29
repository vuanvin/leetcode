#include <leetcode.h>

class Solution {
public:
    struct Node {
        int data;
        vector<int> suff;
        unordered_map<char, Node*> children;
        Node() : data(-1) {}
    };

    vector<int> getNext(const string& p) {
        vector<int> next(p.size());
        next[0] = -1;
        for (int l = 0, r = 1; r < p.size(); l++, r++) {
            next[r] = l;
            if (p[l] == p[r]) {
                while ((next[r] = next[next[r]]) >= 0 && p[next[r]] == p[l])
                    ;
            } else {
                while ((l = next[l]) >= 0 && p[l] != p[r])
                    ;
            }
        }
        return next;
    }

    vector<bool> getPalindrome(const string& s) {
        int n = s.size();
        vector<bool> res(n + 1, false);
        res[n] = true;
        if (n <= 0) return res;
        auto p = s;
        reverse(p.begin(), p.end());
        auto next = getNext(p);
        int i = 0, j = 0;
        while (i < n) {
            while (j >= 0 && s[i] != p[j]) {
                j = next[j];
            }
            i++;
            j++;
        }
        int fr = i - j;
        while (fr < n - 1) {
            res[fr] = true;
            i = fr + 1, j = 0;
            while (i < n) {
                while (j >= 0 && s[i] != p[j]) {
                    j = next[j];
                }
                i++;
                j++;
            }
            int sc = i - j;
            for (int step = sc - fr; fr + step < n;) {
                fr = fr + step;
                res[fr] = true;
            }
        }
        res[n - 1] = true;
        return res;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Node* forward = new Node;
        Node* backward = new Node;
        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            auto pali = getPalindrome(word);
            auto p = forward;
            for (int k = 0; k < word.size(); k++) {
                if (pali[k]) {
                    p->suff.push_back(i);
                }
                auto ch = word[k];
                if (!p->children.count(ch)) {
                    p->children[ch] = new Node;
                }
                p = p->children[ch];
            }
            p->data = i;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            reverse(word.begin(), word.end());
            auto pali = getPalindrome(word);
            auto p = forward;
            if (p->data != -1) {
                if (pali[0]) {
                    auto j = p->data;
                    if (i != j) ans.push_back({j, i});
                }
            }
            int k = 0;
            for (; k < word.size(); k++) {
                auto ch = word[k];
                if (!p->children.count(ch)) {
                    break;
                }
                p = p->children[ch];
                if (pali[k + 1]) {
                    if (p->data != -1) {
                        auto j = p->data;
                        if (i != j) ans.push_back({j, i});
                    }
                }
            }
            if (k == word.size()) {
                for (auto j : p->suff) {
                    if (i != j) ans.push_back({j, i});
                }
            }
        }

        return ans;
    }
};