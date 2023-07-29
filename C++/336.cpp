#include <leetcode.h>

class Solution {
public:
    struct Node {
        int data = -1;
        Node* children[26] = {nullptr};
        Node() : data(-1) {}
    };

    int next[300 + 1];
    bool pali[300 + 1];

    void getNext(const string& p) {
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
    }

    bool* getPalindrome(const string& s) {
        int n = s.size();
        fill(pali, pali + n, false);
        pali[n] = true;
        if (n <= 0) return pali;
        auto p = s;
        reverse(p.begin(), p.end());
        getNext(p);
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
            pali[fr] = true;
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
                pali[fr] = true;
            }
        }
        pali[n - 1] = true;
        return pali;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        std::size_t maxn = 1;
        for (auto& word : words) maxn += word.size();
        Node *ftree = new Node[maxn], *btree = new Node[maxn];
        int fn = 1, bn = 1;
        for (int i = 0; i < words.size(); i++) {
            string word(words[i]);
            auto p = ftree;
            for (int k = 0; k < word.size(); k++) {
                auto ch = word[k] - 'a';
                if (!p->children[ch]) {
                    p->children[ch] = ftree + (fn++);
                    p->children[ch]->data = -1;
                }
                p = p->children[ch];
            }
            p->data = i;

            p = btree;
            reverse(word.begin(), word.end());
            for (int k = 0; k < word.size(); k++) {
                auto ch = word[k] - 'a';
                if (!p->children[ch]) {
                    p->children[ch] = btree + (bn++);
                    p->children[ch]->data = -1;
                }
                p = p->children[ch];
            }
            p->data = i;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            int len = word.size();
            auto pali = getPalindrome(word);
            auto p = btree;
            if (p->data != -1) {
                if (pali[0]) {
                    auto j = p->data;
                    if (i != j) ans.push_back({i, j});
                }
            }
            for (int k = 0; k < len; k++) {
                auto ch = word[k] - 'a';
                if (!p->children[ch]) break;
                p = p->children[ch];
                if (p->data != -1 && pali[k + 1]) {
                    auto j = p->data;
                    if (i != j) ans.push_back({i, j});
                }
            }

            reverse(word.begin(), word.end());
            pali = getPalindrome(word);
            p = ftree;
            if (p->data != -1) {
                if (pali[0]) {
                    auto j = p->data;
                    if (i != j) ans.push_back({j, i});
                }
            }
            for (int k = 0; k < len - 1; k++) {
                auto ch = word[k] - 'a';
                if (!p->children[ch]) break;

                p = p->children[ch];
                if (p->data != -1 && pali[k + 1]) {
                    auto j = p->data;
                    if (i != j) ans.push_back({j, i});
                }
            }
        }
        delete[] ftree;
        delete[] btree;
        return ans;
    }
};