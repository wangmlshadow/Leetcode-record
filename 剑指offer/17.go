func printNumbers(n int) []int {
	cnt := int(math.Pow(10, float64(n))) - 1
	res := make([]int, cnt)
	for i := 1; i <= cnt; i++ {
		res[i - 1] = i
	}
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 Go 提交中击败了90.51%的用户
内存消耗：7.1 MB, 在所有 Go 提交中击败了72.28%的用户
*/