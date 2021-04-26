# 第一题

# 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
# 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
# 你可以按任意顺序返回答案。

# 1.最直接的方法 穷举 时间复杂度为 O(N^2)
# 2.使用Hash表 时间复杂度为 O(N) 空间复杂度(N)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 存储nums值和索引的字典 不需要考虑重复
        index = dict()
        for i, value in enumerate(nums):
            index[value] = i
        for j, value in enumerate(nums):
            other = target - value
            if other in index and index[other] != j:
                return [j, index[other]]
        return [-1, -1]
"""
执行结果：通过
显示详情
执行用时：40 ms, 在所有 Python3 提交中击败了65.95%的用户
内存消耗：14.7 MB, 在所有 Python3 提交中击败了94.78%的用户
"""
