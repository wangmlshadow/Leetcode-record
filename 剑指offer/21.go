func exchange(nums []int) []int {
	left, right := 0, len(nums) - 1
	for left < right {
		if nums[left] % 2 == 0 {
			nums[left], nums[right] = nums[right], nums[left]
			right--
		} else {
			left++
		}
	}
	return nums
}
/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 Go 提交中击败了96.25%的用户
内存消耗：6.8 MB, 在所有 Go 提交中击败了71.06%的用户
*/