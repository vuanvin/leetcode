#include <leetcode.h>

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_map<char, int> ma, mb;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                A++;
            } else {
                ma[secret[i]]++;
                mb[guess[i]]++;
            }
        }
        for (auto [ch, num] : ma) {
            B += min(num, mb[ch]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};