#include <bits/stdc++.h>
using namespace std;

class MagicDictionary {
    unordered_map<string, string> dict;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) {
            auto tmp_word = word;
            for (auto& x : word) {
                auto ch = x;
                x = '*';
                if (dict.count(word)) {
                    dict[word] = "*";
                } else {
                    dict[word] = tmp_word;
                }
                x = ch;
            }
        }
    }
    
    bool search(string searchWord) {
        auto tmp_word = searchWord;
        for (auto& x : searchWord) {
            auto ch = x;
            x = '*';
            if (dict.count(searchWord)) {
                if (dict[searchWord] != tmp_word) return true;
            }
            x = ch;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */