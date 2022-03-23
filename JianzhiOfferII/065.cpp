#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Node {
        vector<Node*> child;
        Node() : child(26, nullptr) {}
    };

    Node *head;

public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 1;
        head = new Node();

        for (auto& word : words) {
            auto p = head;
            int sn = word.size();
            int add = 1;
            int if_add = 0;

            int i = sn - 1;
            for (; i >= 0; i--) {
                auto ch = word[i];

                if (!p->child[ch - 'a']) {
                    break;
                }
                add ++;
                p = p->child[ch - 'a'];
            }

            if (i >= 0 && !count_if(p->child.begin(), p->child.end(), [](Node *p) { return p; })) {
                add = 0;
            }

            for (; i >= 0; i--) {
                auto ch = word[i];

                if (!p->child[ch - 'a']) {
                    p->child[ch - 'a'] = new Node;
                    if_add = 1;
                }
                add ++;
                p = p->child[ch - 'a'];
            }

            ans += if_add * add;
        }
        return ans;
    }
};