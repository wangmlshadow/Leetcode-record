func findRepeatNumber(nums []int) int {
    length := len(nums)
    has := make([]int, length)
    for _, num := range nums {
        if has[num] == 0 {
            has[num] = 1
        } else {
            return num
        }
    }
    return -1
}
/*
执行结果：通过 显示详情 添加备注
执行用时：40 ms, 在所有 Go 提交中击败了89.47%的用户
内存消耗：7.5 MB, 在所有 Go 提交中击败了99.13%的用户
*/