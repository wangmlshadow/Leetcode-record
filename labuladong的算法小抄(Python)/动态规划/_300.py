# -*- coding: utf-8 -*-
"""
Created on Mon Sep 21 16:36:41 2020

@author: Administrator
"""

"""
最长上升子序列 动态规划
给定一个无序的整数数组，找到其中最长上升子序列的长度。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
注意：
子序列和子串不同 子串必须是连续的 而子序列不一定是连续的
"""

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1] * len(nums)# dp[i]表示以nums[i]为最后一位数字的子序列的最大长度
        for i in range(len(nums)):# 时间复杂度O(N^2)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)# 通过dp[0..i - 1]推导dp[i]       
        return max(dp)
"""
执行结果：通过 显示详情
执行用时：1492 ms, 在所有 Python3 提交中击败了8.23%的用户
内存消耗：13.5 MB, 在所有 Python3 提交中击败了63.60%的用户
"""

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 二分查找解法 patience game
        top = [0] * len(nums)# 牌堆 初始化为0 
        piles = 0# 最后结果 整个推理过程类似于patience game游戏规则 
        for num in nums:
            poker = num
            left = 0
            right = piles
            while left < right:
                mid = (left + right) // 2
                if top[mid] >= poker:
                    right = mid
                else:
                    left = mid + 1
            if left == piles:
                piles = piles + 1
            top[left] = poker
        return piles
"""
执行结果：通过 显示详情
执行用时：48 ms, 在所有 Python3 提交中击败了95.96%的用户
内存消耗：13.5 MB, 在所有 Python3 提交中击败了63.60%的用户
"""                    