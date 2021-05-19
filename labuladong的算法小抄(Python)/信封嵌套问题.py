# 第354
"""
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。
"""

# 这其实是最长增长子序列问题的变种LIS

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # 按宽度升序排列 如果宽度一样 按照高度降序排列
        # 两个宽度相同的信封是不能相互包含的 按照高度逆序保证在宽度相同的数对中最多选取一个
        #def compare(a: List[int], b: List[int]) -> bool:
            #return b[1] - a[1] if a[0] == b[0] else a[0] - b[0]
        n = len(envelopes)
        # 一维升序 二维降序
        envelopes = sorted(envelopes, key=lambda x:(x[0],-x[1]))
        #envelopes = sorted(envelopes, key=functools.cmp_to_key(compare))
        #print(envelopes)
        # 对高度数组寻找LIS
        height = [0 for _ in range(n)]
        for i in range(n):
            height[i] = envelopes[i][1]
        return self.lengthOfLIS(height)
    # 最长递增子序列问题    
    def lengthOfLIS(self, nums: List[int]) -> int:
        piles, n = 0, len(nums)
        top = [0 for _ in range(n)]
        for i in range(n):
            poker = nums[i]
            left, right = 0, piles
            # 二分查找插入位置
            while left < right:
                mid = (left + right) // 2
                if top[mid] >= poker:
                    right = mid
                else:
                    left = mid + 1
            if left == piles:
                piles += 1
            top[left] = poker
        return piles
    
"""
执行结果：通过 显示详情 添加备注
执行用时：72 ms, 在所有 Python3 提交中击败了86.53%的用户
内存消耗：16.4 MB, 在所有 Python3 提交中击败了49.08%的用户
"""
