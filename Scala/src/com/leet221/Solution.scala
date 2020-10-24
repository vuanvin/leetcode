package com.leet221

object Solution {
  def maximalSquare(matrix: Array[Array[Char]]): Int = {
    if (matrix == null || matrix.length == 0 || matrix(0).length == 0) return 0
    var maxVal: Int = 0
    for {
      i <- 0 to matrix.length-1
      j <- 0 to matrix(0).length - 1
      if matrix(i)(j) == '1'
    } {
      def exlen(len: Int): Int = {
        if (i + len == matrix.length || j + len == matrix(0).length) return len
        def xcheck(x: Int): Boolean = (x > len) || (matrix(i + len)(j + x) == '1' && xcheck(x + 1))
        def ycheck(y: Int): Boolean = (y > len) || (matrix(i + y)(j + len) == '1' && ycheck(y + 1))
        if (xcheck(0) && ycheck(0)) exlen(len + 1) else len
      }
      maxVal = Math.max(maxVal, exlen(1))
    }
    maxVal * maxVal
  }
}
