#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (i == j) return true;

        char l = tolower(s[i]);
        char r = tolower(s[j]);
        if (l != r ) return false;
        i++; j--;
    }
    return true;
}

int main() {
    cout << (char) toupper('a') << endl;
    cout << (char) tolower('A') << endl;
    cout << (char) tolower('1') << endl;
}