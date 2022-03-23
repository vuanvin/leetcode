#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> trans;

        for(int i = 0; i < order.size(); i++){
            trans[order[i]] = (char)(i + 'a');
        }

        for (auto& word : words) {
            for (auto& ch : word) {
                ch = trans[ch];
            }
        }

        for (int i = 1; i < words.size(); i++) {
            if (words[i] < words[i-1]) {
                return false;
            }
        }

        return true;
    }
};