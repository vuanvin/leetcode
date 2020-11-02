from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left, right, n = 1, 1, len(nums)
        res = [1] * n

        for i in range(n):
            res[i] *= left
            res[n-1-i] *= right
            left *= nums[i]
            right *= nums[n-1-i]

        return res

