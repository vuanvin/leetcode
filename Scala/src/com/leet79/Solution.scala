package com.leet79

object Solution {
  def exist(board: Array[Array[Char]], word: String): Boolean = {
    for {
      i <- 0 to board.length - 1
      j <- 0 to board(0).length - 1
      if board(i)(j) == word(0)
    } {
      def travel(x: Int, y: Int, z: Int): Boolean = {
        if (z == word.length) return true
        if (x < 0 || x >= board.length || y < 0 || y >= board(0).length || board(x)(y) != word(z)) return false
        board(x)(y) = '*'
        if (travel(x+1, y, z+1) || travel(x, y+1, z+1) || travel(x-1, y, z+1) || travel(x, y-1, z+1)) return true
        board(x)(y) = word(z)
        false
      }

      if (travel(i, j, 0)) return true
    }
    false
  }
}
