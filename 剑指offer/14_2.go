func cuttingRope(n int) int {
	if n < 4 {
		return n - 1
	}
	mod := 1000000007
	res := 1
	for n > 4 {
		res = 3 * res % mod
		n -= 3
	}
	return res * n % mod
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了60.45%的用户
*/