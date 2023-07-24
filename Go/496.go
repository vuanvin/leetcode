package leetcode

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	mp := make(map[int]int)
	var stack []int
	for i := len(nums2) - 1; i >= 0; i-- {
		v := nums2[i]
		mp[v] = i
		for len(stack) > 0 && stack[len(stack)-1] <= v {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			nums2[i] = stack[len(stack)-1]
		} else {
			nums2[i] = -1
		}
		stack = append(stack, v)
	}
	for i := 0; i < len(nums1); i++ {
		nums1[i] = nums2[mp[nums1[i]]]
	}
	return nums1
}
