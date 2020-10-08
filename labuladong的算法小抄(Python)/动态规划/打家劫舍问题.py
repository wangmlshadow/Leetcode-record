# -*- coding: utf-8 -*-
"""
Created on Wed Oct  7 20:24:38 2020

@author: Administrator
"""

from typing import List

"""
打家劫舍问题
"""

"""
198

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约
因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统
会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能
够偷窃到的最高金额。
"""
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 存在许多重复情况 超时
        def dp(nums: List[int], start: int) -> int:
            if start >= len(nums): return 0
            # 盗贼对每个房间有两种选择 抢劫 或者 不抢劫
            # 如果不抢劫则跳过此房间 从下一个房间开始选择
            # 如果抢劫 则此房间的nums[i] + 下下的房间做选择的结果
            res = max(dp(nums, start + 1), nums[start] + dp(nums, start + 2))
            return res
        return dp(nums, 0)
    
class Solution:# 在本地运行结果正确 在LeetCode运行结果有问题
    # 使用memo 避免对重叠子问题多次计算
    __memo = dict()
    __nums = []
    def dp(self, start: int) -> int:
        if start >= len(self.__nums):
            return 0
        if start in self.__memo:
            return self.__memo[start]
        res = max(self.dp(start + 1), self.__nums[start] + self.dp(start + 2))
        self.__memo[start] = res
        return res
    def rob(self, nums: List[int]) -> int:
        self.__nums = nums       
        return self.dp(0)
    
        
class Solution:# 将上述代码修改为此形式 运行无误
    # 使用memo 避免对重叠子问题多次计算
    def rob(self, nums: List[int]) -> int:
        memo = dict()
        def dp(nums: List[int], start: int, memo: dict) -> int:
            if start >= len(nums): return 0
            if start in memo: return memo[start]
            # 自顶向下  要求什么 需要先求什么
            res = max(dp(nums, start + 1, memo), nums[start] + dp(nums, start + 2, memo))
            memo[start] = res
            return res
        return dp(nums, 0, memo)
"""
执行结果：通过 显示详情
执行用时：56 ms, 在所有 Python3 提交中击败了9.73%的用户
内存消耗：13.5 MB, 在所有 Python3 提交中击败了5.35%的用户
"""

class Solution:
    def rob(self, nums: List[int]) -> int:
        # 不用额外函数 仍需dp数组 自底向上
        n = len(nums)
        # dp[i]表示从第i间房子开始抢劫 最多能抢到多少钱
        # base case： dp[n] = 0
        dp = [0 for i in range(n + 2)]
        for i in range(n - 1, -1, -1):
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2])
        return dp[0] # 比上述用两个函数快了很多
"""
执行结果：通过 显示详情
执行用时：40 ms, 在所有 Python3 提交中击败了71.55%的用户
内存消耗：13.4 MB, 在所有 Python3 提交中击败了23.15%的用户
"""   

class Solution:
    def rob(self, nums: List[int]) -> int:
        # 可以看到dp[i] 仅仅和 dp[i + 1] dp[i + 2]有关 那么就可以不使用dp数组
        dp_i_1 = 0
        dp_i_2 = 0
        dp_i = 0        
        for i in range(len(nums) - 1, -1, -1):
            dp_i = max(dp_i_1, nums[i] + dp_i_2)
            dp_i_2 = dp_i_1
            dp_i_1 = dp_i
        return dp_i
"""
执行结果：通过 显示详情
执行用时：28 ms, 在所有 Python3 提交中击败了99.33%的用户
内存消耗：13.3 MB, 在所有 Python3 提交中击败了60.81%的用户
"""




"""
213
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都
围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防
盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到
的最高金额。

相比于上一题 所有房子围成了一个圈 也就是说第一个房子与最后一个房子是相邻状态
此时我们就有两种选择情况：1.在第一栋到倒数第二栋范围内抢劫 2.在第二栋到最后一栋范围内抢劫
"""

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        def robRange(nums: List[int], start: int, end: int) -> int:
            dp_i = 0
            dp_i_1 = 0
            dp_i_2 = 0
            for i in range(end, start - 1, -1):
                dp_i = max(dp_i_1, nums[i] + dp_i_2)
                dp_i_2 = dp_i_1
                dp_i_1 = dp_i
            return dp_i
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1))
"""
执行结果：通过 显示详情
执行用时：52 ms, 在所有 Python3 提交中击败了10.51%的用户
内存消耗：13.2 MB, 在所有 Python3 提交中击败了88.87%的用户
"""




"""
337

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一
个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察
之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的
房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

街道排列变成二叉树了 相连两节点全被盗会报警 改变一下状态转移方程就行了
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    memo = dict()
    def rob(self, root: TreeNode) -> int:
        if root == None: return 0
        if root in self.memo: return self.memo[root]
        # 抢劫 然后去下下家
        do_it = root.val + (0 if (root.left == None) else self.rob(root.left.left) + self.rob(root.left.right)) + (0 if (root.right == None) else self.rob(root.right.left) + self.rob(root.right.right))
        # 不抢劫 然后去下家
        not_do = self.rob(root.left) + self.rob(root.right)
        res = max(do_it, not_do)
        self.memo[root] = res
        return res
"""
执行结果：通过 显示详情
执行用时：76 ms, 在所有 Python3 提交中击败了23.38%的用户
内存消耗：16.8 MB, 在所有 Python3 提交中击败了8.60%的用户
"""        

class Solution:
    def rob(self, root: TreeNode) -> int:
        def dp(root: TreeNode) -> List[int]:
            # 返回一个大小为2的数组 arr
            # arr[0] 表示不抢root得到的最大金钱数
            # arr[1] 表示抢root得到的最大金钱数
            if root == None: return [0, 0]
            left = dp(root.left)
            right = dp(root.right)
            rob = root.val + left[0] + right[0]
            not_rob = max(left[0], left[1]) + max(right[0], right[1])
            return [not_rob, rob]
        res = dp(root)
        return max(res[0], res[1])
"""
执行结果：通过 显示详情
执行用时：84 ms, 在所有 Python3 提交中击败了11.83%的用户
内存消耗：15.2 MB, 在所有 Python3 提交中击败了82.25%的用户
"""

# 看到一个解法 思路与上述一样 只是将dp的返回值从list修改为int, int 快了很多 试一下
class Solution:
    def rob(self, root: TreeNode) -> int:
        def dp(root: TreeNode):
            # 返回一个大小为2的数组 arr
            # arr[0] 表示不抢root得到的最大金钱数
            # arr[1] 表示抢root得到的最大金钱数
            if root == None: return 0, 0
            left = dp(root.left)
            right = dp(root.right)
            rob = root.val + left[0] + right[0]
            not_rob = max(left) + max(right)
            return not_rob, rob

        return max(dp(root))
"""
执行结果：通过 显示详情
执行用时：68 ms, 在所有 Python3 提交中击败了47.53%的用户
内存消耗：15.4 MB, 在所有 Python3 提交中击败了27.86%的用户
"""

















