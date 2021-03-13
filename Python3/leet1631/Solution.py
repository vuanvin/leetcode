from typing import List

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows = len(heights)
        columns = len(heights[0])
        absdiff = [[10_000_000 for j in range(columns)] for i in range(rows)]
        without = [[True for j in range(columns)] for i in range(rows)]

        absdiff[0][0], without[0][0] = 0, False
        path = [(0, 0)]
        while len(path):
            ele = path.pop(0)
            if ele == (rows-1, columns-1):
                return absdiff[rows-1][columns-1]

            neighbors = [ (ele[0]+i, ele[1]+j) for i, j in [(0,1), (0,-1), (-1,0), (1,0)] if 0 <= ele[0]+i < rows
                         and 0 <= ele[1]+j < columns]
            for v in neighbors:
                abs_v = max(abs(heights[v[0]][v[1]] - heights[ele[0]][ele[1]]), absdiff[ele[0]][ele[1]])
                absdiff[v[0]][v[1]] = min(absdiff[v[0]][v[1]], abs_v)

                if without[v[0]][v[1]]:
                    path.append((v[0], v[1]))
                    without[v[0]][v[1]] = False

            id = 0
            for i, v in enumerate(path):
                if absdiff[v[0]][v[1]] < absdiff[path[id][0]][path[id][1]]:
                    id = i
            path[0], path[id] = path[id], path[0]


        return absdiff[rows-1][columns-1]


