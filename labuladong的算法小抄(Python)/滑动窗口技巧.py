# 第76题
# 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
# 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

# 暴力解法 尝试所有可能性 比较找出最小子串 复杂度 N^2
# 左右指针
# 1.初始化使得left=right=0
# 2.不断增加right直到window中的字符串符合要求
# 3.此时停止增加right 转而不断增大left缩小window 直到window中的字符串不符合要求
# 4.重复2 3 直到right到达字符串s的尽头

# 使用左右指针
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 记录最短子串的开始位置和长度
        start, minLen = 0, math.inf
        # 初始化左右指针
        left, right = 0, 0
        # 使用字典 用于判断window是否已经满足条件
        window = dict()
        needs = dict()
        for c in t:
            if c not in needs:
                needs[c] = 1
            else:
                needs[c] = needs[c] + 1
        
        # 用于判断window中的字符是否已经满足条件
        # match表示已经匹配了多少种字符 注意不是 多少个 
        match = 0
        
        while right < len(s):
            c1 = s[right]
            # 如果c1存在于字符串t中 在window中加上
            if c1 in needs:
                if c1 not in window:
                    window[c1] = 1
                else:
                    window[c1] = window[c1] + 1
                # 判断window中字符c1数量是否已经与字符串t中字符c1数量一致
                if window[c1] == needs[c1]:# 等于号 因为window中c1字符数量可能大于needs中c1的数量
                    match = match + 1# 已匹配的字符种类数加一
            right = right + 1
            
            # window满足条件 执行步骤3
            while match == len(needs):
                if right - left < minLen:
                    # 更新最小子串的位置和长度
                    start = left
                    minLen = right - left# 因为上面right已经加过一 此处计算长度不需要再加一
                c2 = s[left]
                # c2属于needs的键 即c2在字符串t内
                if c2 in needs:
                    # left右移 窗口变小 对应字符的数量减一
                    window[c2] = window[c2] - 1
                    # 如果window中c2的数量小于needs中c2的数量 此时已匹配的字符种类减一
                    if window[c2] < needs[c2]:
                        match = match - 1
                left = left + 1
        return "" if minLen == math.inf else s[start:start+minLen]
"""
执行结果：通过
显示详情
执行用时：116 ms, 在所有 Python3 提交中击败了50.68%的用户
内存消耗：15.2 MB, 在所有 Python3 提交中击败了41.84%的用户
"""

# 第438题
"""
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列可以相同也可以不同的字符串。
不考虑答案输出的顺序。

"""
# 与上一题相似 只需要改一下即可
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = list()
        left, right = 0, 0
        needs = dict()
        window = dict()
        for c in p:
            if c not in needs:
                needs[c] = 1
            else:
                needs[c] = needs[c] + 1
        match = 0
        
        while right < len(s):
            c1 = s[right]
            if c1 in needs:
                if c1 not in window:
                    window[c1] = 1
                else:
                    window[c1] = window[c1] + 1
                if window[c1] == needs[c1]:
                    match = match + 1
            right = right + 1
            
            while match == len(needs):
                # 如果window的大小合适就把初始索引left加入res
                if right - left == len(p):
                    res.append(left)
                c2 = s[left]
                if c2 in needs:
                    window[c2] = window[c2] - 1
                    if window[c2] < needs[c2]:
                        match = match - 1
                left = left + 1
        return res
"""
执行结果：通过
显示详情
执行用时：108 ms, 在所有 Python3 提交中击败了78.18%的用户
内存消耗：15.4 MB, 在所有 Python3 提交中击败了87.76%的用户
"""

# 第3题
# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
# 注意 不含重复字符
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        window = dict()
        res = 0# 记录最长长度
        
        while right < len(s):
            c1 = s[right]
            if c1 not in window:
                window[c1] = 1
            else:
                window[c1] = window[c1] + 1
            right = right + 1
            # 如果window中出现重复字符
            # 开始移动left缩小窗口
            while window[c1] > 1:
                c2 = s[left]
                window[c2] = window[c2] - 1# 此处不需要判断window是否存在c2 因为window是left-right一定有c2
                left = left + 1
            res = max(res, right - left)
        return res
      
      
