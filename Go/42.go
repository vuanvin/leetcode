package leetcode

func trap(height []int) int {
	n, ans := len(height), 0
	l, r := 0, n-1
	hl, hr := height[l], height[r]
	for l < r-1 {
		if hl <= hr {
			l++
			if height[l] < hl {
				ans += hl - height[l]
			} else {
				hl = height[l]
			}
		} else {
			r--
			if height[r] < hr {
				ans += hr - height[r]
			} else {
				hr = height[r]
			}
		}
	}
	return ans
}
