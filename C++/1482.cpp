#include <leetcode.h>

class TreeAncestor {
    vector<vector<int>> T;
    static const int H = 100;

public:
    TreeAncestor(int n, vector<int>& parent) {
        T.resize(n, vector<int>(H + 1, -1));

        for (int i = 1; i < n; i++) {
            int j = parent[i];

            for (int k = 1; k <= H; k++) {
                if (j == -1) {
                    break;
                }
                T[i][k] = j;
                j = parent[j];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (; k > H; k -= H) {
            node = T[node][H];
            if (node < 0) return -1;
        }
        return T[node][k];
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */