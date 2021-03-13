//
// Created by YUANYIN on 2020/11/05.
//

#ifndef C_SOLUTION_H
#define C_SOLUTION_H

#include "../leetcode.h"

class Solution {
public:
    int res = 0;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            if (similar(beginWord, wordList[i])) {
                swap(wordList[i], wordList[0]);
                dfs(endWord, wordList, 0);
                swap(wordList[i], wordList[0]);
            }
        }

        return res;
    }

    void dfs(const string& endWord, vector<string>& wordList, int first) {
        if (endWord == wordList[first]) {
            if (res == 0) res = first+2;
            else res = min(res, first+2);
            return;
        }
        if (first == wordList.size()-1) return;

        for (int i = first+1; i < wordList.size(); i++) {
            if (similar(wordList[first], wordList[i])) {
                swap(wordList[first+1], wordList[i]);
                dfs(endWord, wordList, first+1);
                swap(wordList[first+1], wordList[i]);
            }
        }
    }

    bool similar(const string& s, const string& t) {
        int diff = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) diff ++;
        }
        return diff == 1;
    }
};

#endif //C_SOLUTION_H
