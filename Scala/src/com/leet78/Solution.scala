package com.leet78

object Solution {
  def subsets(nums: Array[Int]): List[List[Int]] = {
    val n = nums.length
    var res: List[List[Int]] = Nil

    def dfs(k: Int, arr: List[Int]): Unit = {
      if (k == n) res = arr :: res
      else {
        dfs(k+1, nums(k)::arr)
        dfs(k+1, arr)
      }
    }
    dfs(0, Nil)
    res
  }
}
