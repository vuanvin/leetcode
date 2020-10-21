from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n: int = len(nums)
        if n == 0:
            return 0
        if n <= 3:
            return max(nums)

        res = nums[:]
        res[2] = nums[0] + nums[2]

        for i in range(3, n-1):
            value = max(res[i-2], res[i-3]) + nums[i]
            res[i] = value
        r1 = max(res[-2], res[-3])

        res = nums[:]
        res[-3] = nums[-1] + nums[-3]
        for i in range(n-4, 0, -1):
            value = max(res[i+2], res[i+3])
            res[i] = value
        r2 = max(res[1], res[2])
        return max(r1, r2)
