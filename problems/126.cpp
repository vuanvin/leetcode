#include <leetcode.h>

class Solution {
public:
    using FromSet = unordered_map<string, set<string>>;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return res;
        dict.erase(beginWord);
        unordered_map<string, int> steps = {{beginWord, 0}};
        FromSet from = {{beginWord, {}}};
        int step = 0, wordLen = beginWord.size();
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        while (!q.empty() & !found) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);  // have erase from dict
                        }
                        if (!dict.count(nextWord)) continue;
                        dict.erase(nextWord);
                        q.push(nextWord);
                        from[nextWord].insert(currWord);
                        steps[nextWord] = step;
                        if (nextWord == endWord) found = true;
                    }
                    nextWord[j] = origin;
                }
            }
        }
        if (found) {
            vector<string> path = {endWord};
            backtrack(res, endWord, from, path);
        }
        return res;
    }

    void backtrack(vector<vector<string>>& res, const string& node, FromSet& from, vector<string>& path) {
        if (from[node].empty()) {
            res.emplace_back(path.rbegin(), path.rend());
            return;
        }
        for (const string& parent : from[node]) {
            path.push_back(parent);
            backtrack(res, parent, from, path);
            path.pop_back();
        }
    }
};