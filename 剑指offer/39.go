func majorityElement(nums []int) int {
	res := 0
	cnt := 0

	for _, value := range nums {
		if value == res {
			cnt++
		} else {
			if cnt == 0 {
				res = value
			} else {
				cnt--
			}
		}
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：16 ms, 在所有 Go 提交中击败了95.98%的用户
内存消耗：6 MB, 在所有 Go 提交中击败了74.24%的用户
*/