# 第392
"""
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
"""

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # 双指针
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len(s)
"""
执行结果：通过 显示详情 添加备注
执行用时：56 ms, 在所有 Python3 提交中击败了16.45%的用户
内存消耗：14.9 MB, 在所有 Python3 提交中击败了70.32%的用户
"""

# 进阶 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        # 对 t 进行预处理
        # 对于多个字符串s 可以将预处理部分抽出
        index = [None for _ in range(256)]
        for i in range(n):
            c = t[i]
            if index[ord(c)] == None:
                index[ord(c)] = []
            index[ord(c)].append(i)
        
        # 串t上的指针
        j = 0
        # 借助index查找s[i]
        for i in range(m):
            c = s[i]
            # t中没有字符c
            if index[ord(c)] is None:
                return False
            pos = self.leftBound(index[ord(c)], j)
            # 二分搜索区间没有找到字符c
            if pos == len(index[ord(c)]):
                return False
            # 向前移动指针j
            j = index[ord(c)][pos] + 1
        return True
            
            
    def leftBound(self, arr: List[int], tar: int) -> int:
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if tar > arr[mid]:
                lo = mid + 1
            else:
                hi = mid
        return lo
"""
执行结果：通过 显示详情 添加备注
执行用时：40 ms, 在所有 Python3 提交中击败了74.20%的用户
内存消耗：15.1 MB, 在所有 Python3 提交中击败了15.98%的用户
"""
