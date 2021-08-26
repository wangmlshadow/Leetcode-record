type helper struct {
	pos int
	cnt int
}

func firstUniqChar(s string) byte {
    all := make(map[byte]*helper)
	for i := 0; i < len(s); i++ {
		if _, ok := all[s[i]]; !ok {
			all[s[i]] = &helper{i, 1}
		} else {
			all[s[i]].cnt = all[s[i]].cnt + 1
		}
	}

	var res byte = ' '
	pos := len(s)
	for k, v := range all {
		if v.cnt == 1 && v.pos < pos {
			res = k
			pos = v.pos
		}
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：52 ms, 在所有 Go 提交中击败了18.96%的用户
内存消耗：5.4 MB, 在所有 Go 提交中击败了22.46%的用户
*/