#include <leetcode.h>

class Solution {
private:
    int m, n;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'P';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                dfs(board, nx, ny);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] == 'P' ? 'O' : 'X';
            }
        }
    }
};