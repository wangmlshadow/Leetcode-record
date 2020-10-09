"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Python中str比大小 
        # 比较两个字符串的从前到后的字符大小 按照字符的ASCII码比
        if not strs:
            return ""
        minStr = min(strs)
        maxStr = max(strs)        
        for i in range(len(minStr)):
            if minStr[i] != maxStr[i]:
                return minStr[:i]
        return minStr
