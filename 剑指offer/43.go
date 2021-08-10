func countDigitOne(n int) int {
	result, digits := 0, 1
	high, low, cur := n / 10, 0, n % 10

	for high != 0 || cur != 0 {
		if cur == 0 {
			result += high * digits
		} else if cur == 1 {
			result += high * digits + low + 1
		} else {
			result += (high + 1) * digits
		}

		low = cur * digits + low 
		cur = high % 10
		high = high / 10
		digits = digits * 10
	}

	return result
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了63.74%的用户
*/