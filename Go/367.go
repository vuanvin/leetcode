package leetcode

func isPerfectSquare(num int) bool {
	l, h := 0, num
	for l <= h {
		m := (l + h) / 2
		s := m * m
		if s < num {
			l = m + 1
		} else if s > num {
			h = m - 1
		} else {
			return true
		}
	}
	return false
}
