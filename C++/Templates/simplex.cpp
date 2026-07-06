#include <bits/stdc++.h>
using namespace std;

using Vector = vector<double>;
using Matrix = vector<vector<double>>;

class Simplex {
private:
    void gaussian(size_t row, size_t col) {
        auto norm = tableau[row][col];
        for (size_t y = 0; y < num_columns; y++) {
            tableau[row][y] /= norm;
        }

        for (size_t x = 0; x < num_rows; x++) {
            if (x == row || tableau[x][col] == 0) continue;
            norm = tableau[x][col];
            for (size_t y = 0; y < num_columns; y++) {
                tableau[x][y] -= norm * tableau[row][y];
            }
        }
    }

    bool find_pivot(size_t& row, size_t& col) {
        row = 0, col = 0;
        auto mn = numeric_limits<double>::max();

        // choice rule in Devex algorithm
        for (size_t y = 0; y < num_columns - 1; y++) {
            if (basic_variables.count(y)) continue;

            auto target_factor = tableau[num_rows - 1][y];
            if (target_factor < mn) {
                mn = target_factor;
                col = y;
            }
        }

        if (mn > 0) {
            return false;
        }

        mn = numeric_limits<double>::max();
        for (size_t x = 0; x < num_rows - 1; x++) {
            if (tableau[x][col] == 0) continue;
            auto res = tableau[x][num_columns - 1] / tableau[x][col];
            if (res > 0 && res < mn) {
                row = x;
                mn = res;
            }
        }

        size_t replaced_variable = 0;
        for (auto v : basic_variables) {
            if (tableau[row][v] != 0) {
                replaced_variable = v;
                break;
            }
        }
        basic_variables.erase(replaced_variable);
        basic_variables.insert(col);

        return true;
    }

public:
    Simplex(Matrix A, Vector B, Vector C, unordered_set<size_t> S) {
        num_rows = A.size() + 1;
        num_columns = A[0].size() + 1;
        tableau.resize(num_rows, Vector(num_columns, 0));
        // A
        for (int x = 0; x < num_rows - 1; x++) {
            for (int y = 0; y < num_columns - 1; y++) {
                tableau[x][y] = A[x][y];
            }
        }
        // B
        for (int x = 0; x < num_rows - 1; x++) {
            tableau[x][num_columns - 1] = B[x];
        }
        // -C
        for (int y = 0; y < num_columns - 1; y++) {
            tableau[num_rows - 1][y] = -C[y];
        }

        basic_variables = S;

        print_tableau();
    }

    void print_tableau() {
        cout << fixed << setprecision(2);
        for (size_t i = 0; i < num_rows; i++) {
            for (size_t j = 0; j < num_columns; j++) {
                cout << tableau[i][j] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }

    double Solve() {
        size_t row, col;

        while (find_pivot(row, col)) {
            gaussian(row, col);
            print_tableau();
        }

        return tableau[num_rows - 1][num_columns - 1];
    }

private:
    Matrix tableau;
    size_t num_columns, num_rows;
    unordered_set<size_t> basic_variables;
};

int main() {
    Matrix A = {{3, 2, 1, 1, 0}, {2, 5, 3, 0, 1}};
    unordered_set<size_t> S{{3, 4}};
    Vector B = {10, 15};
    Vector C = {2, 3, 4, 0, 0};  // maximize 2x + 3y + 4z

    Simplex simplex(A, B, C, S);
    cout << simplex.Solve() << endl;
}