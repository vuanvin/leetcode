package com.leet215

object Solution {
  def findKthLargest(nums: Array[Int], k: Int): Int = {
    if (k == 1) return nums.max
    val res = nums.sorted
    res(res.length - k)
  }
}
