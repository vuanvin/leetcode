from typing import List


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        idx = list(range(len(nums)))
        idx = sorted(idx, key=lambda x: nums[x])
        for i in range(len(idx)+1):
            j = i+1
            while j < len(idx) and nums[idx[j]] - nums[idx[i]] <= t:
                if abs(idx[j] - idx[i]) <= k:
                    return True
                j += 1

        return False