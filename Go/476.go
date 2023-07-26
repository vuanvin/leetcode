package leetcode

func findComplement(num int) int {
	bit, tmp := 0, 0
	for ; num > 0; bit++ {
		tmp = tmp<<1 + (1 - num&1)
		num = num >> 1
	}
	for ; bit > 0; bit-- {
		num = num<<1 + tmp&1
		tmp = tmp >> 1
	}
	return num
}
