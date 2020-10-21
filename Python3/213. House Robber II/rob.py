from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n: int = len(nums)
        if n == 0:
            return 0
        if n <= 2:
            return max(nums[:2])
        
        max(nums[-3:])

