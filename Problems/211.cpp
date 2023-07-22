#include <leetcode.h>

class WordDictionary {
public:
    struct Node {
        vector<Node*> children;
        int val;
        Node(int v = 0) : children(26, nullptr), val(v) {}
    };

    WordDictionary() { root = new Node(1); }

    void addWord(string word) {
        auto p = root;
        for (auto ch : word) {
            auto id = ch - 'a';
            if (!p->children[id]) {
                p->children[id] = new Node;
            }
            p = p->children[id];
        }
        p->val = 1;
    }

    bool dfs(Node* r, string word) {
        if (r == nullptr) return false;
        if (word.empty()) return r->val == 1;
        auto ch = word[0];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(r->children[i], word.substr(1))) return true;
            }
        } else {
            return dfs(r->children[ch - 'a'], word.substr(1));
        }
        return false;
    }
    bool search(string word) { return dfs(root, word); }

private:
    Node* root;
};