#include <leetcode.h>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;
        for (auto ch : magazine) {
            mag[ch]++;
        }
        for (auto ch : ransomNote) {
            if (--mag[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};