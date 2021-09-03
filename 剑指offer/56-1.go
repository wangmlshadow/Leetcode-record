func singleNumbers(nums []int) []int {
	ret, div := 0, 1
	for _, num := range nums {
		ret ^= num
	}

	for (div & ret) == 0 {
		div <<= 1
	}

	a, b := 0, 0
	for _, num := range nums {
		if (div & num) == 0 {
			a ^= num
		} else {
			b ^= num
		}
	}

	return []int{a, b}
}
/*
执行结果：通过 显示详情 添加备注
执行用时：24 ms, 在所有 Go 提交中击败了19.82%的用户
内存消耗：6.3 MB, 在所有 Go 提交中击败了98.65%的用户
通过测试用例：35 / 35
*/