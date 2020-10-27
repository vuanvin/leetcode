package com.leet57

object Solution {
  def insert(intervals: Array[Array[Int]], newInterval: Array[Int]): Array[Array[Int]] = {
    if (intervals.length == 0) return intervals.appended(newInterval)
    val n = intervals.length
    if (newInterval(1) < intervals(0)(0)) 
    def left(i: Int): Int = if (i+1 < n   && intervals(i)(1) < newInterval(0)) left(i+1) else i
    def right(i: Int): Int = if (i-1 >= 0 && intervals(i)(0) > newInterval(1)) right(i-1) else i
    val li = left(0)
    val ri = right(intervals.length-1)
    val il = Math.min(intervals(li)(0), newInterval(0))
    val ir = Math.max(intervals(ri)(1), newInterval(1))


  }
}
