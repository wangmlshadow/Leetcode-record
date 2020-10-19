# -*- coding: utf-8 -*-
"""
Created on Tue Oct 13 10:52:22 2020

@author: Administrator
"""

"""
1143

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某
些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序
列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。
"""
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # 递归解法
        def dp(i, j):
            if i == -1 or j == -1:# 空串
                return 0
            if text1[i] == text2[j]:# 两元素相等 那么此元素必定在最长子序列中LCS
                return dp(i - 1, j - 1) + 1
            else:# 比较那种情况下LCS更长
                return max(dp(i - 1, j), dp(i, j - 1))
        return dp(len(text1) - 1, len(text2) - 1)# 超时
    

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # 使用dp table
        m, n = len(text1), len(text2)
        # 构建dp table
        # base case [0][i] [j][0] 为 0
        dp = [[0] * (n + 1) for i in range(m + 1)]
        # 状态转移
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
"""
执行结果：通过 显示详情
执行用时：372 ms, 在所有 Python3 提交中击败了96.87%的用户
内存消耗：21.1 MB, 在所有 Python3 提交中击败了40.05%的用户
"""






























