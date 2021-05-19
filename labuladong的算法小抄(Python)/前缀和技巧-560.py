# 前缀和：前0个到前n个元素和的序列

# 主要用于处理数组区间问题

# 第560题
# 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
# 说明 :
# 数组的长度为 [1, 20,000]。
# 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # 利用前缀和
        n = len(nums)
        # 构造前缀和
        sumList = [0] * (n + 1)
        for i, value in enumerate(nums):
            sumList[i + 1] = sumList[i] + value
        
        ans = 0
        # 穷举所有子数组
        for i in range(1, n + 1):
            for j in range(i):
                # 子数组 j .. i - 1
                if sumList[i] - sumList[j] == k:
                    ans += 1
        return ans
      
# 上述算法流程没问题 但是并不是最优的 

# 优化算法
# 上述算法循环做的是：计算有多少个 j 能使得 sumList[i] 和 sumList[j] 的差为 k
# 优化：直接记录下有几个 sunList[j] 和 sumList[i] - k 相等 直接更新结果 省去内循环
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        # 使用字典 记录前缀和出现的次数
        preSum = dict()
        # base case
        preSum[0] = 1# 前缀和为0出现一次
        ans, sum0_i = 0, 0
        for i in range(n):
            sum0_i += nums[i]
            # 我们想找的前缀和 nums[0 .. j]
            sum0_j = sum0_i - k
            # 如果前面有这个前缀和 直接更新答案
            if sum0_j in preSum:
                ans += preSum[sum0_j]
            # 把前缀和 nums[0 .. i] 加入并记录出现次数
            if sum0_i in preSum:
                preSum[sum0_i] += 1
            else:
                preSum[sum0_i] = 1
        return ans
    
"""
执行结果：通过
显示详情
执行用时：76 ms, 在所有 Python3 提交中击败了97.60%的用户
内存消耗：17 MB, 在所有 Python3 提交中击败了39.73%的用户
"""
