func replaceSpace(s string) string {
    // 直接用string的Replace即可
	res := strings.Replace(s, " ", "%20", -1)
	return res
}

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了84.95%的用户
*/