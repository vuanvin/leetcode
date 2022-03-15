#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> wordId;
vector<vector<int>> edge;
int nNode = 0;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    for (auto & word : wordList) {
        if (!wordId.count(word)) {
            wordId[word] = nNode++;
            edge.emplace_back();
        }
    }

    if (!wordId.count(endWord)) {
        return 0;
    }

    if (!wordId.count(beginWord)) {
        wordId[beginWord] = nNode++;
        edge.emplace_back();
    }

    wordList.push_back(beginWord);

    for (auto & word : wordList) {
        auto id = wordId[word];
        for (char & it : word) {
            char tmp = it;
            it = '*';
            if (!wordId.count(word)) {
                wordId[word] = nNode++;
                edge.emplace_back();
            }
            auto id2 = wordId[word];
            edge[id].push_back(id2);
            edge[id2].push_back(id);
            it = tmp;
        }
    }

    vector<int> dist(nNode, INT_MAX);
    int beginId = wordId[beginWord],  endId = wordId[endWord];
    dist[beginId] = 0;

    queue<int> Q;
    Q.push(beginId);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        if (x == endId) { return dist[endId] / 2 + 1; }

        for (int & it : edge[x]) {
            if (dist[it] == INT_MAX) {
                dist[it] = dist[x] + 1;
                Q.push(it);
            }
        }
    }

    return 0;
}