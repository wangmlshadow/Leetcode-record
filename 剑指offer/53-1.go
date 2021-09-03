func search(nums []int, target int) int {
	res, left, right := 0, 0, len(nums) - 1

	for left <= right {
		mid := (left + right) / 2
		if target > nums[mid] {
			left = mid + 1
		} else if target < nums[mid] {
			right = mid - 1
		} else {
			res = 1
			
			for temp := mid - 1; temp >= 0 && target == nums[temp]; temp-- {
				res++
			}
			for temp := mid + 1; temp < len(nums) && target == nums[temp]; temp++ {
				res++
			}

			break
		}
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了98.24%的用户
内存消耗：3.9 MB, 在所有 Go 提交中击败了58.66%的用户
通过测试用例：88 / 88
*/