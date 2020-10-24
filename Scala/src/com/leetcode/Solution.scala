package com.leetcode

import java.util

object Solution {
  def simplifyPath(path: String): String = {
    var str: String = "o"
    return path
  }

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

  def letterCombinations(digits: String): List[String] = {
    if (digits.length == 0) return Nil
    val num2letters = Map('2'->"abc", '3'->"def", '4'->"ghi", '5'->"jkl", '6'->"mno", '7'->"pqrs", '8'->"tuv", '9'->"wxyz")
    var res: List[String] = Nil
    if (digits.length == 1) return num2letters(digits(0)).toList.map(a => ""+a)
    val firstLetters = num2letters(digits(0))
    val otherLetters = letterCombinations(digits.substring(1))

    for {
      first <- firstLetters
      letters <- otherLetters
    } {
      res = (first +: letters) :: res
    }
    return res
  }

  def rotate(nums: Array[Int], k: Int): Unit = {
    if (k == 0) return
    val n: Int = nums.length
    for (s <- 0 until k) {
      val first = nums(n-1)
      for (i <- (n-1).until(0, -1)) {
        val tmp = nums(i)
        nums(i) = nums(i-1)
        nums(i-1) = tmp
      }
    }
  }

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
