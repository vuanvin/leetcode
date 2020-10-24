package com.leet20

object Solution {
  def isValid(s: String): Boolean = {
    val left = Array('{', '[', '(')
    val right = Map[Char, Char]('}'->'{', ')'->'(', ']'->'[')
    var li: List[Char] = Nil
    for (c <- s.toList) {
      if (left contains c)
        li = c :: li
      else if (li.isEmpty || li(0) != right(c))
        return false
      else
        li = li.drop(1)
    }
    return li.isEmpty
  }
}
