package leetcode

func isSubsequence(s string, t string) bool {
	i, n := 0, len(t)
	for _, c := range s {
		for ; i < n && rune(t[i]) != c; i++ {
		}
		if i == n {
			return false
		}
		i++
	}
	return true
}
