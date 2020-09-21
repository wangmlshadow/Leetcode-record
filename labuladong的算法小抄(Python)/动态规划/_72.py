# -*- coding: utf-8 -*-
"""
Created on Mon Sep 21 19:25:02 2020

@author: Administrator
"""

"""
编辑距离 动态规划
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
"""

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 递归解决 超时
        def dp(i, j):
            # base case
            if i == -1: return j + 1
            if j == -1: return i + 1
            
            if word1[i] == word2[j]:
                return dp(i - 1, j - 1)
            else:# 返回 通过再word1插入 删除 替换操作中所需步骤最少的
                return min(dp(i, j - 1) + 1, dp(i - 1, j) + 1, dp(i - 1, j - 1) + 1)
                # 这里做了很多重复计算
                # 解决重复问题可以使用备忘录或者动态规划
                # 递归为自顶向下 dp为自底向上
        return dp(len(word1) - 1, len(word2) - 1)# 从word1 word2最后一个字符开始编辑
    
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 动态规划
        m = len(word1)
        n = len(word2)
        dp = [([0] * (n + 1)) for i in range(m + 1)]
        
        for i in range(1, m + 1):
            dp[i][0] = i
        for j in range(1, n + 1):
            dp[0][j] = j
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:# 通过dp[i - 1][j]  dp[i][j - 1]  dp[i - 1][j - 1]  得到 dp[i][j]
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
        return dp[m][n]
"""
执行结果：通过 显示详情
执行用时：200 ms, 在所有 Python3 提交中击败了72.24%的用户
内存消耗：16.8 MB, 在所有 Python3 提交中击败了76.43%的用户
"""