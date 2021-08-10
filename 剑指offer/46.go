func translateNum(num int) int {
	numStr := strconv.Itoa(num)

	if len(numStr) == 0 {
		return 0
	}
	if len(numStr) == 1 {
		return 1
	}
	if len(numStr) == 2 {
		if num <= 25 {
			return 2
		}
		return 1
	}

	cnt_1, cnt_2, cnt_3 := 1, 0, 0
	if numStr[0] == '1' || (numStr[0] == '2' && numStr[1] < '6') {
		cnt_2 = 2
	} else {
		cnt_2 = 1
	}

	for i := 2; i < len(numStr); i++ {
		if numStr[i - 1] == '1' || (numStr[i - 1] == '2' && numStr[i] < '6') {
			cnt_3 = cnt_1 + cnt_2
		} else {
			cnt_3 = cnt_2
		}

		cnt_1 = cnt_2
		cnt_2 = cnt_3
	}

	return cnt_3
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了82.59%的用户
*/