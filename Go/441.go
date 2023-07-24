package leetcode

func arrangeCoins(n int) int {
	l, r := 0, n
	for l <= r {
		m := (l + r) / 2
		s := m * (m + 1) / 2
		if s < n {
			l = m + 1
		} else if s > n {
			r = m - 1
		} else {
			return m
		}
	}
	return min(l, r)
}
