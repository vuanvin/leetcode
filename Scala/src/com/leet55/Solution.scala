package com.leet55

object Solution {
  def canJump(nums: Array[Int]): Boolean = {
    val endpos = nums.length - 1
    def jump(curr: Int, goal: Int): Boolean = {
      if (curr > goal) curr == nums.length else {
        val newgoal = Math.min(Math.max(goal, nums(curr) + curr), endpos)
        jump(curr + 1, newgoal)
      }
    }
    jump(0, Math.min(endpos, nums(0)))
  }
}
