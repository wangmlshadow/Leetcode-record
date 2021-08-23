func lengthOfLongestSubstring(s string) int {
	if len(s) <= 1 {
		return len(s)
	}

	has := make(map[byte]bool)
	res, left, right := 0, 0, -1

	for i := 0; i < len(s); i++ {
		if v, ok := has[s[i]]; !ok || v == false {
			has[s[i]] = true
			right++
		} else {
			if res < right - left + 1 {
				res = right - left + 1
			}

			for left <= right && s[left] != s[i] {
				has[s[left]] = false
				left++
			}

			left++
			right++
		}
	}

	if res < right - left + 1 {
		res = right - left + 1
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 Go 提交中击败了75.85%的用户
内存消耗：2.7 MB, 在所有 Go 提交中击败了78.61%的用户
*/