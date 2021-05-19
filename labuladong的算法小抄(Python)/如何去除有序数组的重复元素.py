# 第26
"""
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
"""

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # 快慢指针
        if not nums:
            return 0
        n = len(nums)
        slow, fast = 0, 1
        while fast < n:
            if nums[fast] != nums[slow]:
                slow += 1
                nums[slow] = nums[fast]
            fast += 1
        return slow + 1
"""
执行结果：通过 显示详情 添加备注
执行用时：32 ms, 在所有 Python3 提交中击败了99.29%的用户
内存消耗：15.8 MB, 在所有 Python3 提交中击败了36.55%的用户
"""
