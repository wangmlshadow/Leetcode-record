# 第5
# 给你一个字符串 s，找到 s 中最长的回文子串。

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ''
        for i in range(len(s)):
            # 以s[i]为中心的最长回文子串
            s1 = self.palindrome(s, i, i)
            # 以s[i] s[i+1]为中心的回文子串
            s2 = self.palindrome(s, i, i + 1)
            res = res if len(res) > len(s1) else s1
            res = res if len(res) > len(s2) else s2
        return res
        
    # 以指定位置为中心 寻找最长回文子串
    # 给定两个位置 l r 使得可以同时处理回文子串长度为奇数 长度为偶数 两种情况
    def palindrome(self, s: str, l: int, r: int) -> str:
        # 放置索引越界
        while l >= 0 and r < len(s) and s[l] == s[r]:
            # 向两边扩张
            l -= 1
            r += 1
        # 返回以指定位置为中心的最长回文子串
        return s[l + 1:r]
"""
执行结果：通过 显示详情 添加备注
执行用时：852 ms, 在所有 Python3 提交中击败了83.48%的用户
内存消耗：15 MB, 在所有 Python3 提交中击败了77.10%的用户
"""
