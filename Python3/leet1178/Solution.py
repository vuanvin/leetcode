from typing import List

class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        first_cond = []
        for word in words:
            first_cond.append([])
            first_cond[-1] = [False] * 26
            for w in word:
                first_cond[-1][ord(w) - ord('a')] = True

        res = [0] * len(puzzles)

        for i, p in enumerate(puzzles):
            table = [False] * 26
            for v in p:
                table[ord(v) - ord('a')] = True

            for j, w in enumerate(words):
                if first_cond[j][ord(p[0]) - ord('a')] == False:
                    continue

                key = True
                for k in range(26):
                    if first_cond[j][k] and (not table[k]):
                        key = False
                        break

                if key:
                    res[i] += 1

        return res
