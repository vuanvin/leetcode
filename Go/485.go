package leetcode

func findMaxConsecutiveOnes(nums []int) int {
	mx, res := 0, 0
	for _, v := range nums {
		if v == 0 {
			mx = max(res, mx)
			res = 0
		} else {
			res++
		}
	}
	return max(mx, res)
}
