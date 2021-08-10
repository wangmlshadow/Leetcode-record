func permutation(s string) []string {
	resSet := make(map[string]int)
	used := make([]bool, 0)
	for i := 0; i < len(s); i++ {
		used = append(used, false)
	}

	createStr(&resSet, used, s, "")

	resSlice := []string{}
	for key, _ := range resSet {
		resSlice = append(resSlice, key)
	}

	return resSlice
}

func createStr(pResSet *map[string]int, used []bool, s string, res string) {
	if len(s) == len(res) {
		(*pResSet)[res] = 1
		return
	}
	for i := 0; i < len(s); i++ {
		if !used[i] {
			used[i] = true
			createStr(pResSet, used, s, res + s[i:i+1])
			used[i] = false
		}
	}
}
/*
执行结果：通过 显示详情 添加备注
执行用时：88 ms, 在所有 Go 提交中击败了16.28%的用户
内存消耗：8.2 MB, 在所有 Go 提交中击败了23.05%的用户
*/