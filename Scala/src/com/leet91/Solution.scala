package com.leet91

object Solution {
  def numDecodings(s: String): Int = {
    if (s == null || s.length == 0 || s(0) == '0') return 0
    if (s.length == 1) return 1

    val arr: Array[Int] = new Array[Int](s.length)
    arr(0) = 1
    arr(1) = (if (s(0) == '1' || (s(0) == '2' && s(1) <= '6')) 1 else 0) + (if (s(1) == '0') 0 else 1)

    for (i <- 2 to s.length-1) {
      arr(i) = (
        if (arr(i-1) == 0) 0 else {
          if (s(i) == '0') 0 else arr(i-1)
        }
      ) + (
        if (arr(i-2) == 0) 0 else {
          if (s(i-1) == '1' || (s(i-1) == '2' && s(i) <= '6')) arr(i-2) else 0
        }
      )
    }
    arr(arr.length-1)
  }
}

object Solution1 {
  def numDecodings(s: String): Int = {
    def decode(s: String): Int = {
      if (s.length == 0) 1
      else if (s.length == 1) {
        if (s(0) == '0') 0 else 1
      }
      else {
        if (s(0) == '0') 0
        else if (s(0) == '1' || (s(0) == '2' && s(1) <= '6')) {
          decode(s.substring(1)) + decode(s.substring(2))
        }
        else {
          decode(s.substring(1))
        }
      }
    }
    if (s == null || s.length == 0) 0 else decode(s)
  }
}