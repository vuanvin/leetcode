package com.leet17

object Solution {
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
}
