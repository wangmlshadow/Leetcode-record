func minArray(numbers []int) int {
	if len(numbers) == 0 {
		return 0
	}
	res := numbers[0]
	for i := len(numbers) - 1; i > 0; i-- {
		if res >= numbers[i] {
			res = numbers[i]
		} else {
			break
		}
	}
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了91.02%的用户
内存消耗：3.1 MB, 在所有 Go 提交中击败了100.00%的用户
*/