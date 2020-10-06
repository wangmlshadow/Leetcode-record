# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 20:22:00 2020

@author: Administrator
"""

"""
KMP 字符匹配算法
模式串 pat 长度为 M
文本串 txt 长度为 N
计算 pat 相关的 dp 数组

"""

from typing import str

class KMP:
    def __init__(self, pat: str):
        self.__pat = pat
        M = len(pat)
        # dp[状态][字符] = 下一个状态
        self.__dp = [[[0] * 256] for i in range(M)]
        # base case
        self.__dp[0][int(pat[0])] = 1
        # 影子状态 X 初始为 0
        X = 0
        # 构建状态转移图
        for j in range(1, M):
            for c in range(256):
                self.__dp[j][c] = self.__dp[X][c]
            self.__dp[j][int(pat[j])] = j + 1
            # 更新影子状态
            X = self.__dp[X][int(pat[j])]
    
    def search(self, txt: str) -> int:
        M = len(self.__pat)
        N = len(txt)
        # pat的初始状态为0
        j = 0
        for i in range(N):
            # 计算pat的下一个状态
            j = self.__dp[j][int(txt[i])]
            # 到达终止状态 返回结果
            if j == M:
                return i - M + 1
        # 没到达终止态 匹配失败
        return -1
        
