package com.leet925

object Solution {
  def isLongPressedName(name: String, typed: String): Boolean = {
    val n: Int = name.length
    val m: Int = typed.length
    var i: Int = 0
    var j: Int = 0
    while (i < n && j < m) {
      if (name(i) != typed(j)) return false
      j += 1
      if (i+1 == n || name(i+1) != name(i)) {
        while (j < m && typed(j) == name(i)) j += 1
      }
      i += 1;
    }
    i == n && j == m
  }
}
