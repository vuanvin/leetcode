package com.leetcode

class MinStack() {

  /** initialize your data structure here. */
  var nums : List[Int] = Nil

  def push(x: Int) {
    nums = x :: nums
  }

  def pop() {
    nums = nums.tail
  }

  def top(): Int = {
    nums.head
  }

  def getMin(): Int = {
    nums.reduce((a, b) => Math.min(a, b))
  }

}
