#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> data;

public:
    // NumMatrix(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     data.assign(m, vector<int>(n));
    //     data[0][0] = matrix[0][0];
    //     for (int i = 1; i < m; i++) { data[i][0] = data[i-1][0] + matrix[i][0]; }
    //     for (int j = 1; j < n; j++) { data[0][j] = data[0][j-1] + matrix[0][j]; }

    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             data[i][j] = data[i-1][j] + data[i][j-1] - data[i-1][j-1] + matrix[i][j];
    //         }
    //     }
    // }

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        data.assign(m, vector<int>(n));
        data[0][0] = matrix[0][0];
        for (int j = 1; j < n; j++) { data[0][j] = data[0][j-1] + matrix[0][j]; }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                data[i][j] = data[i-1][j] + matrix[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                data[i][j] += data[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = data[row2][col2];
        int b = (row1 == 0) ? 0 : data[row1-1][col2];
        int c = (col1 == 0) ? 0 : data[row2][col1-1];
        int d = (row1 == 0 || col1 == 0) ? 0 : data[row1-1][col1-1];
        return a - b - c + d;
    }
};