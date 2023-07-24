package leetcode

type Mat [2][2]int

func multiply(a, b Mat) (c Mat) {
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
		}
	}
	return
}

func pow(a Mat, n int) Mat {
	res := Mat{{1, 0}, {0, 1}}
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			res = multiply(res, a)
		}
		a = multiply(a, a)
	}
	return res
}

func fib(n int) int {
	if n < 2 {
		return n
	}
	res := pow(Mat{{1, 1}, {1, 0}}, n-1)
	return res[0][0]
}
