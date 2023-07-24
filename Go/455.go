package leetcode

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	i, n := 0, len(s)
	for k, v := range g {
		for ; i < n && s[i] < v; i++ {
		}
		if i == n {
			return k
		}
		i++
	}

	return len(g)
}
