# -*- coding: utf-8 -*-
"""
Created on Mon Sep 28 15:04:44 2020

@author: Administrator
"""

"""
最长回文子序列 动态规划

给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度
可以假设 s 的最大长度为 1000

注意：子序列并非连续子数组
"""

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # dp[i][j]表示在子串s[i..j]中最长回文子序列的长度
        l = len(s)
        # dp数组初始化为0
        dp = [[0] * l for i in range(l)]
        # base case 
        for i in range(l):
            dp[i][i] = 1
        
        # dp的状态转移 反向遍历
        for i in range(l - 1, -1, -1):
            for j in range(i + 1, l):
                # 状态转移方程
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][l - 1]

"""
执行结果：通过 显示详情
执行用时：1632 ms, 在所有 Python3 提交中击败了53.90%的用户
内存消耗：29.6 MB, 在所有 Python3 提交中击败了37.78%的用户
"""            
        
