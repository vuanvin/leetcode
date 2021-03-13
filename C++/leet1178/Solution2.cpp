//
// Created by YUANYIN on 2021/02/26.
//

#include "Solution2.h"

struct Node {
    int freq = 0;
    Node* child[26];
    Node() {
        for (Node* &ch : child) { ch = nullptr; }
    }
};

class Solution {
private:
    Node* root;

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        root = new Node();

        auto add_word = [&] (const string& word) {
            Node* p = root;
            for (char ch : word) {
                if (!p->child[ch-'a']) {
                    p->child[ch - 'a'] = new Node();
                }
                p = p->child[ch - 'a'];
            }
            ++ p->freq;
        };

        for (string word : words) {
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            add_word(word);
        }

        function<int(const string&, char, Node*, int)> find = [&](const string& puzzle, char required, Node* p, int pos) {
            if (!p) { return 0; }
            if (pos == 7) { return p->freq; }

            int ret = find(puzzle, required, p->child[puzzle[pos] - 'a'], pos+1);

            if (puzzle[pos] != required) {
                ret += find(puzzle, required, p, pos + 1);
            }

            return  ret;
        };

        vector<int> ans;
        for (string puzzle : puzzles) {
            char required = puzzle[0];
            sort(puzzle.begin(), puzzle.end());
            ans.push_back(find(puzzle, required, root, 0));
        }
        return ans;
    }
};
