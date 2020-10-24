package com.leet1024

object Solution {
  def videoStitching(clips: Array[Array[Int]], T: Int): Int = {
    if (clips == null || clips.length == 0) return -1

    val cls = clips.sortBy(x => x(1)).sortBy(x => x(0))
    val nums: Array[Int] = new Array[Int](100+5)

    for (clip <- cls if clip(0) <= T) {
      if (clip(0) == 0) {
        for (pos <- 0 to clip(1)) {
          nums(pos) = 1
        }
      } else {
        val st = nums(clip(0))
        if (st == 0) return -1
        for (pos <- clip(0) to clip(1)) {
          if (nums(pos) == 0) {
            nums(pos) = st + 1
          }
        }
      }
    }
    if (nums(T) == 0) -1 else nums(T)
  }
}
