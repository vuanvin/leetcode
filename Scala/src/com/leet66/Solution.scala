package com.leet66

object Solution {
  def plusOne(digits: Array[Int]): Array[Int] = {
    val n = digits.length
    digits(n-1) += 1
    for (i <- 0 to n-1) {
      if (digits(n-1-i) == 10) {
        digits(n-1-i) = 1
        digits(n-2-i) += 1
      }
    }
    if (digits(0) == 10) {
      digits(0) = 0
      1 +: digits
    }
    else
      digits
  }
}
