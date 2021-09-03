func singleNumber(nums []int) int {
	allNums := make(map[int]bool)
	for _, n := range nums {
		if _, ok := allNums[n]; !ok {
			allNums[n] = true
		} else {
			allNums[n] = false
		}
	}

	var res int
	for key, val:= range allNums {
		if val == true {
			res = key
			break
		}
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：24 ms, 在所有 Go 提交中击败了83.41%的用户
内存消耗：6.6 MB, 在所有 Go 提交中击败了30.73%的用户
通过测试用例：32 / 32
*/