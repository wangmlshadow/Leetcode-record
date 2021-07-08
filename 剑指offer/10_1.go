func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	mod := 1000000007
	n0, n1, temp := 0, 1, 0
	for n > 1 {
		temp = n0
		n0 = n1 % mod
		n1 = (n1 + temp) % mod
		n--
	}
	return n1
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了100.00%的用户
*/