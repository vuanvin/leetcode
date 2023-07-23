package leetcode

func numJewelsInStones(jewels string, stones string) int {
	m := make(map[rune]bool)
	for _, u := range jewels {
		m[u] = true
	}
	ans := 0
	for _, u := range stones {
		if _, ok := m[u]; ok {
			ans++
		}
	}
	return ans
}
