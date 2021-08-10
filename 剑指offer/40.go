func getLeastNumbers(arr []int, k int) []int {
	sort.Ints(arr)
	return arr[:k]
}
/*
执行结果：通过 显示详情 添加备注
执行用时：36 ms, 在所有 Go 提交中击败了44.98%的用户
内存消耗：6.5 MB, 在所有 Go 提交中击败了77.13%的用户
*/