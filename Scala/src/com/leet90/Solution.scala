package com.leet90

class Solution {
  def subsetsWithDup(nums: Array[Int]): List[List[Int]] = {
    val n = nums.length
    var res: List[List[Int]] = Nil
    val nu = nums.sorted

    def dfs(k: Int, arr: List[Int]): Unit = {
      if (k == n) res = arr :: res
      else {
        def go(i: Int): Int = if (i+k < n && nu(k) == nu(k+i)) go(i+1) else i
        val i = go(0)
        var ar: List[Int] = Nil
        for (j <- 0 to i) {
          dfs(k+i, ar:::arr)
          ar = nu(k) :: ar
        }

      }
    }
    dfs(0, Nil)
    res
  }
}
