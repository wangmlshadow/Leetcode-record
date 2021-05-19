# 第268
"""
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

进阶：

你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
"""

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # 借助异或操作
        # 一个数和它本身做异或运算结果为0 一个数和0做异或运算还是它本身
        n = len(nums)
        res = 0
        # 与新补的索引异或一下
        res ^= n
        # 和其它元素、索引做异或
        for i in range(n):
            res ^= i ^ nums[i]
        return res
"""
执行结果：通过 显示详情 添加备注
执行用时：56 ms, 在所有 Python3 提交中击败了44.87%的用户
内存消耗：15.8 MB, 在所有 Python3 提交中击败了34.80%的用户
"""
