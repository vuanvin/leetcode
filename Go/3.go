package leetcode

func lengthOfLongestSubstring(s string) int {
	m := map[byte]int{}
	n := len(s)
	var ans int = 0
	var l int = 0
	for r := 0; r < n; r++ {
		m[s[r]]++
		for m[s[r]] > 1 {
			m[s[l]]--
			l++
		}
		ans = max(ans, r-l+1)
	}
	return ans
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
