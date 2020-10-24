package com.leet13

object Solution {
  def romanToInt(s: String): Int = {
    val numVal = Map('I'-> 1, 'V'->5, 'X'->10, 'L'->50, 'C'->100, 'D'->500, 'M'->1000)
    val left = Map('V'->'I', 'X'->'I', 'L'->'X', 'C'->'X', 'D'->'C', 'M'->'C')
    var res = 0
    var old: Char = 'M'
    for (c <- s) {
      res += numVal(c)
      if (left.contains(c) && left(c) == old) {
        res -= 2 * numVal(old)
      }
      old = c
    }
    res
  }
}
