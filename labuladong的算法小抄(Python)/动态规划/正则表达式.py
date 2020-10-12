# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 20:08:00 2020

@author: Administrator
"""
"""
10

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
"""

class Solution: # 暴力递归
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s
        first_match = bool(s) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':# 有星号
            # 星号匹配其前面字符的0个 self.isMatch(self, s, p[2:])
            # 星号匹配其前面字符的1个 first_match and self.isMatch(self, s[1:], p)
            return self.isMatch(self, s, p[2:]) or first_match and self.isMatch(self, s[1:], p)
        else:
            return first_match and self.isMatch(self, s[1:], p[1:])
"""
执行结果：通过 显示详情
执行用时：1600 ms, 在所有 Python3 提交中击败了5.01%的用户
内存消耗：13.4 MB, 在所有 Python3 提交中击败了41.62%的用户

暴力递归竟然通过了 真没想到
C++中暴力递归并没有通过
"""

# 使用memo减少重复计算
class Solution: # memo
    def isMatch(self, s: str, p: str) -> bool:
        memo = dict()
        def dp(i, j):
            if (i, j) in memo: return memo[(i, j)]
            if j == len(p): return i == len(s)
            first_match = i < len(s) and p[j] in {s[i], '.'}
            if j <= len(p) - 2 and p[j + 1] == '*':
                ans = dp(i, j + 2) or first_match and dp(i + 1, j)
            else:
                ans = first_match and dp(i + 1, j + 1)
            memo[(i, j)] = ans
            return ans
        return dp(0, 0)

"""
执行结果: 通过 显示详情
执行用时：44 ms, 在所有 Python3 提交中击败了99.04%的用户
内存消耗：13.5 MB, 在所有 Python3 提交中击败了22.50%的用户
"""



























