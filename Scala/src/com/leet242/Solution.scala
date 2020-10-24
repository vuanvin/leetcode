package com.leet242

object Solution {
  def isAnagram(s: String, t: String): Boolean = {
    if (s.length != t.length) return false
    val n = s.length
    val array: Array[Int] = new Array[Int](26)
    for (i <- 0 to 26-1) array(i) = 0
    for (i <- 0 to n-1) {
      array(s(i)-'a') += 1
      array(t(i)-'a') -= 1
    }
    for (arg <- array)
      if (arg != 0) return false

    true
  }
}
