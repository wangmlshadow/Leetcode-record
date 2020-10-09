"""
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        left = 0
        #right = 1
        res = 1
        for i in range(1, len(s)):
            for j in range(left, i):
                if s[j] == s[i]:
                    left = j + 1
                    break
            res = max(res, i - left + 1)
        return res
                
"""
执行结果：通过 显示详情
执行用时：88 ms, 在所有 Python3 提交中击败了41.23%的用户
内存消耗：13.4 MB, 在所有 Python3 提交中击败了36.05%的用户
""" 
