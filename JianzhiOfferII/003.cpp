#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n+1);
    if (n == 0) {
        res[0] = 0; return res;
    }
    res[0] = 0; res[1] = 1;

    int j = 0, cnt = 2;
    for (int i = 2; i <= n; i++) {
        if (j == cnt) {
            cnt = i; j = 0;
        }
        res[i] = res[j++] + 1;
    }
    return res;
}

int main() {

}