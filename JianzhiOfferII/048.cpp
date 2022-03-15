#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const string null = "null";

string serialize(TreeNode* root) {
    string res="[";
    queue<TreeNode*> Q; 
    if (root) {
        Q.push(root);
        res += to_string(root->val);
    }

    while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        auto l = p->left;
        res += ",";
        if (l) {
            res += to_string(l->val);
            Q.push(l);
        } else {
            res += null;
        }

        res += ",";
        auto r = p->right;
        if (r) {
            res += to_string(r->val);
            Q.push(r);
        } else {
            res += null;
        }
    }

    res += "]";
    return res;
}

TreeNode* deserialize(string data) {
    TreeNode *root = nullptr;
    int n = data.size();

    if (n <= 2) {
        return root;
    }

    data[n-1] = ',';
    int i = 0;

    auto f = [&] {
        int j = ++ i;
        while (i < n && data[i] != ',') ++ i;
        return data.substr(j, i - j);
    };

    auto word = f();
    root = new TreeNode(stoi(word));
    queue<TreeNode*> Q;
    Q.push(root);

    while (i < n - 1) {
        auto p = Q.front();
        Q.pop();

        auto word = f();
        cout << word << endl;
        if (word == null) {
            p->left = nullptr;
        } else {
            p->left = new TreeNode(stoi(word));
            Q.push(p->left);
        }

        auto word = f();
        cout << word << endl;
        if (word == null) {
            p->right = nullptr;
        } else {
            p->right = new TreeNode(stoi(word));
            Q.push(p->right);
        }
    }

    return root;
}