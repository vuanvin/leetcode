#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        bool exist;
        vector<Node*> child;
        Node(bool e = false) : exist(e), child(26, nullptr) {}
    };

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto head = new Node();

        for (auto& word : dictionary) {
            auto p = head;
            for (auto ch : word) {
                if (!p->child[ch - 'a']) {
                    p->child[ch - 'a'] = new Node();
                }
                p = p->child[ch - 'a'];
            }
            p->exist = true;
        }

        string ans;
        auto first = sentence.begin();

        while (true) {
            auto last = find(first, sentence.end(), ' ');

            string word(first, last);
            auto p = head;
            int n = word.size();
            int i;
            for (i = 0; i < n; i++) {
                auto ch = word[i];
                p = p->child[ch - 'a'];

                if (!p) {
                    ans += word;
                    break;
                } else if (p->exist) {
                    ans += word.substr(0, i + 1);
                    break;
                }
            }

            if (i == n) {
                ans += word;
            }

            if (last == sentence.end()) break;
            ans += " ";
            first = last + 1;
        }

        return ans;
    }
};