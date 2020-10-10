"""
567

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。
"""

import string

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1 = sorted(s1)
        for i in range(0, len(s2) - len(s1) + 1):
            tmp = sorted(s2[i:i + len(s1)])
            if s1 == tmp:
                return True
        return False


class Solution: # 下面这个快得多
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        all = {k:0 for k in string.ascii_lowercase}
        cur = {k:0 for k in string.ascii_lowercase}
        for s in s1:
            all[s] += 1
        for i in range(len(s2)):
            cur[s2[i]] += 1
            if i >= len(s1):
                cur[s2[i - len(s1)]] -= 1
            if all == cur:
                return True
        return False
