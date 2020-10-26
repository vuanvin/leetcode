package com.leet1365

object Solution {
  def smallerNumbersThanCurrent(nums: Array[Int]): Array[Int] = {
    val idss: Array[Int] = new Array[Int](nums.length)

    def init(i: Int): Unit = { idss(i) = i; if (i + 1 < idss.length) init(i+1) }
    init(0)
    val ids = idss.sortBy(x => nums(x))

    val res: Array[Int] = new Array[Int](nums.length)
    res(ids(0)) = 0
    for (i <- 1 to ids.length-1) {
      res(ids(i)) = if (nums(ids(i)) == nums(ids(i-1))) res(ids(i-1)) else i
    }
    res
  }
}
