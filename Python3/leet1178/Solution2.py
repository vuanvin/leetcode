from typing import List

class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        words = [set(list(w)) for w in words]
        words = [w for w in words if len(w) <= 7]

        res = [0] * len(puzzles)
        for i, p in enumerate(puzzles):
            for j, w in enumerate(words):
                if p[0] in w:
                    continue

                key = True

                for v in w:
                    if not v in p:
                        key = False
                        break

                if key:
                    res[i] += 1

        return res
