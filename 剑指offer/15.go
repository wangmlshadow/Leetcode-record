func hammingWeight(num uint32) int {
    res := 0
	for num != 0 {
		res++
		num = num & (num - 1)
	}
	return res
}
/*
执行结果：通过显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了58.97%的用户
*/