# -*- coding: utf-8 -*-
"""
Created on Mon Sep 28 15:56:59 2020

@author: Administrator
"""

"""
预测赢家 动态规划

给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任
意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到
没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
"""

class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        # 初始化dp数组
        # dp[i][j][0]表示nums[i..j]中 先手 最多可拿到的分数
        # dp[i][j][1]表示nums[i..j]中 后手 最多可拿到的分数
        dp = [[[0 for i in range(2)] for i in range(n)] for i in range(n)]
        # base case
        for i in range(n):
            dp[i][i][0] = nums[i]
            #dp[i][i][1] = 0
        # 斜着遍历数组
        for l in range(2, n + 1):  # l为此时正在计算的子数组长度 从2到n
            for i in range(n - l + 1):
                j = l + i - 1
                # 先手选择最左边或最右边的分数
                left = nums[i] + dp[i + 1][j][1]
                right = nums[j] + dp[i][j - 1][1]
                # 套用状态转移方程
                if left > right:
                    dp[i][j][0] = left
                    dp[i][j][1] = dp[i + 1][j][0]
                else:
                    dp[i][j][0] = right
                    dp[i][j][1] = dp[i][j - 1][0]
        return dp[0][n - 1][0] >= dp[0][n - 1][1]
    
"""
执行结果：通过 显示详情
执行用时：52 ms, 在所有 Python3 提交中击败了39.35%的用户
内存消耗：13.3 MB, 在所有 Python3 提交中击败了75.78%的用户
"""
        