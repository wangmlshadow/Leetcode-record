func maxSubArray(nums []int) int {
	res, pre := nums[0], 0

	for _, value := range nums {
		pre = max(value, value + pre)
		res = max(res, pre)
	}

	return res
}

func max(v1, v2 int) int {
	if v1 > v2 {
		return v1
	}
	return v2
}

/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 Go 提交中击败了90.30%的用户
内存消耗：7.1 MB, 在所有 Go 提交中击败了32.84%的用户
*/