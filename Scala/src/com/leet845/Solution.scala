package com.leet845

object Solution {
  def longestMountain(A: Array[Int]): Int = {
    def view(start: Int): Int = {
      if (start + 3 > A.length) 0 else if (A(start) >= A(start+1)) {
        view(start+1)
      } else {
        def up(s: Int): Int = if (s+1 < A.length && A(s) < A(s+1)) up(s+1) else s
        def down(s: Int): Int = if (s+1 < A.length && A(s) > A(s+1)) down(s+1) else s

        val mid = up(start)
        val en = up(mid)
        if (en > mid) Math.max(en-start, view(en)) else view(en)
      }
    }
    view(0)
  }
}
