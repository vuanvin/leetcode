package leetcode

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guess(num int) int {
	return num
}

func guessNumber(n int) int {
	l, r := 0, n
	for l < r {
		m := (r-l)/2 + l
		if guess(m) > 0 {
			l = m + 1
		} else {
			r = m
		}
	}
	return l
}
