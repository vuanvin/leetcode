package leetcode

func longestPalindrome(s string) string {
	if s == "" {
		return ""
	}
	l, r := 0, 0
	for i := 0; i < len(s); i++ {
		l1, r1 := expand(s, i, i)
		l2, r2 := expand(s, i, i+1)
		if r1-l1 > r-l {
			l, r = l1, r1
		}
		if r2-l2 > r-l {
			l, r = l2, r2
		}
	}
	return s[l : r+1]
}

func expand(s string, l, r int) (int, int) {
	for ; l >= 0 && r < len(s) && s[l] == s[r]; l, r = l-1, r+1 {
	}
	return l + 1, r - 1
}
