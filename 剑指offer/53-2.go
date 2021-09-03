func missingNumber(nums []int) int {
	res, left, right := -1, 0, len(nums) - 1

	for left <= right {
		mid := (left + right) / 2

		if mid == nums[mid] {
			left = mid + 1
		} else {
			if mid - 1 >= 0 && mid - 1 == nums[mid - 1] {
				res = mid
				break
			}

			if left == right {
				res = mid
				break
			}

			right = mid
		}
	}

	if res == -1 {
		res = len(nums)
	}

	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：16 ms, 在所有 Go 提交中击败了84.88%的用户
内存消耗：6.1 MB, 在所有 Go 提交中击败了62.75%的用户
通过测试用例：122 / 122
*/