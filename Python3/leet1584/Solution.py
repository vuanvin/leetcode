from typing import List


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        dist = lambda x, y: abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1])

        n = len(points)
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                edges.append((dist(i, j), i, j))

        edges.sort()

        res, num = 0, 1
        father = list(range(len(points)))

        def get_father(p):
            while father[p] != p:
                father[p] = father[father[p]]
                p = father[p]
            return p


        for length, x, y in edges:
            if get_father(x) != get_father(y):
                father[get_father(y)] = get_father(x)
                res += length
                num += 1
                if num == n:
                    break

        return res



