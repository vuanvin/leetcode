#include <leetcode.h>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        if (x == 0 && y == 0) continue;
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && abs(board[ni][nj]) == 1) {
                            cnt++;
                        }
                    }
                }
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) {
                    board[i][j] = -1;
                }
                if (board[i][j] == 0 && cnt == 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};