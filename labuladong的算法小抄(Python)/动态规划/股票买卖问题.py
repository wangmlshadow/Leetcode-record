# -*- coding: utf-8 -*-
"""
Created on Tue Oct  6 15:52:06 2020

@author: Administrator
"""

from typing import List

"""
# 股票交易类问题合集
动态规划 
dp[i][k][0 or 1] 在第i天 我们持有(1)/没有持有(0)股票 最多交易k次 
状态转移方程：
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
注意交易次数在买入股票时加一

初始状态
dp[-1][k][0] = 0     表示在没开始的时候 利润为0
dp[-1][k][1] = -inf  在没开始时不可能持有股票 因此用-inf表示这种不可能的情况
dp[i][0][0] = 0      因为k = 0表示不允许交易 因此利润为0
dp[i][0][1] = -inf   不允许交易时不可能持有股票 用-inf表示

"""



"""
121

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

此处 k = 1
"""
class Solution:# 只交易一次 k = 1 dp[天数][交易次数][0 or 1] -> dp[天数][0 or 1]
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)# 天数 0 <= i <= n        
        if n == 0:
            return 0        
        dp = [[0 for i in range(2)] for j in range(n)]        
        for i in range(0, n):
            if i == 0:
                # base case
                # 第一天不持有股票（利润 = 0）/第一天持有股票（利润 = -prices[0]）
                # dp[i][1][0] = max(dp[-1][1][0], dp[-1][1][1] + prices[0]) = 0
                # dp[i][1][1] = max(dp[-1][1][1], dp[-1][1][0] - prices[0]) = -prices[0]
                dp[i][0] = 0
                dp[i][1] = -prices[i]
                continue
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], -prices[i])
            # 此处不能是dp[i][1] = max(dp[i - 1][1], dp[i -  1][0] - prices[i]) 因为只交易一次 而dp[i -  1][0] 可能代表之前已经有过交易
        return dp[n - 1][0]

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 可以从上述代码看到 每一个状态只与相邻的状态有关 因此可以省去dp
        n = len(prices)
        if n == 0: return 0
        dp_i_0 = 0
        dp_i_1 = float("-inf")
        for i in range(n):
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i_1 = max(dp_i_1, -prices[i])
        return dp_i_0
"""
提交时间  提交结果  运行时间   内存消耗    语言
几秒前	    通过	   52 ms	  14.2 MB   Python3
13 分钟前	 通过	   80 ms	  16.8 MB	  Python3
6 个月前	 通过	   24 ms	  12.6 MB	  C++

前两种运行状态 分别为上述两种解法的运行状态
"""


"""
122

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

k = 无穷
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # k为无穷时 从数学上理解 k = 无穷时 k-1 和 k 可以看做一样的
        n = len(prices)
        if n == 0: return 0
        dp = [[0 for i in range(2)] for j in range(n)]
        
        for i in range(n):
            if i == 0:
                dp[i][0] = 0
                dp[i][1] = -prices[i]
                continue
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
            # 注意此处dp[i][1] 对于k = 1 和 k = 无穷 时的写法
        return dp[n - 1][0]
"""
执行结果：通过 显示详情
执行用时：108 ms, 在所有 Python3 提交中击败了9.77%的用户
内存消耗：16.4 MB, 在所有 Python3 提交中击败了5.00%的用户
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 与k = 1的情况一样 同样可以不使用dp数组
        n = len(prices)
        if n == 0: return 0
        dp_i_0 = 0
        dp_i_1 = -prices[0]
        
        for i in range(1, n):
            temp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i_1 = max(dp_i_1, temp - prices[i])
        return dp_i_0
"""
执行结果：通过 显示详情
执行用时：80 ms, 在所有 Python3 提交中击败了70.94%的用户
内存消耗：14.2 MB, 在所有 Python3 提交中击败了99.11%的用户
"""


"""
309
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

k = inf + condition(冷冻期)

冷冻期为1天 则状态转移方程中 dp[i][] 经卖出或买入而改变的状态与 dp[i - 2][] 有关 即隔了一天
"""
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[0 for i in range(2)] for j in range(n)]
        for i in range(n):
            if i == 0: # 第一天
                dp[i][0] = 0
                dp[i][1] = -prices[i]
                continue
            if i == 1: # 第二天
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
                continue
            # 状态转移方程 
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
            # 卖出后买入需要隔一天 因此此处为dp[i - 2][0]
        return dp[n - 1][0]
"""
执行结果：通过 显示详情
执行用时：48 ms, 在所有 Python3 提交中击败了88.86%的用户
内存消耗：13.9 MB, 在所有 Python3 提交中击败了21.00%的用户
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp_i_0 = 0
        dp_i_1 = float("-inf")
        dp_pre_0 = 0 # 表示dp[i - 2][0]
        for i in range(n):
            temp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i])
            dp_pre_0 = temp
        return dp_i_0
"""
执行结果：通过 显示详情
执行用时：32 ms, 在所有 Python3 提交中击败了99.97%的用户
内存消耗：13.3 MB, 在所有 Python3 提交中击败了97.86%的用户
"""



"""
714
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续
购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

k = inf + fee(手续费)
"""
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[0 for i in range(2)] for j in range(n)]
        
        for i in range(n):
            if i == 0:
                dp[i][0] = 0
                dp[i][1] = -prices[i]
                continue
            # 假设每次在股票卖出时给手续费 
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
            # 也可以改成买入时给出手续费 只需要将 - fee 换个地方
        return dp[n - 1][0]
"""
执行结果：通过 显示详情
执行用时：1336 ms, 在所有 Python3 提交中击败了8.41%的用户
内存消耗：23.3 MB, 在所有 Python3 提交中击败了5.03%的用户
"""

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        if n == 0: return 0
        dp_i_0 = 0
        dp_i_1 = float("-inf")
        for i in range(n):
            # 此处在买入时给手续费
            temp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee)
        return dp_i_0




"""
123

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

k = 2
"""
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[[0 for i in range(2)] for k in range(3)] for j in range(n)]
        for i in range(n):
            for k in range(2, 0, -1):
                if i == 0:
                    # base case
                    dp[i][k][0] = 0
                    dp[i][k][1] = -prices[i]
                    continue
                # 状态转移方程 注意 买入时 交易次数加一
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
        return dp[n - 1][2][0]
"""
执行结果：通过 显示详情
执行用时：2980 ms, 在所有 Python3 提交中击败了5.01%的用户
内存消耗：63.6 MB, 在所有 Python3 提交中击败了6.47%的用户
"""               

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # k = 2 较小 仍然可以不使用dp数组
        n = len(prices)
        if n == 0: return 0
        dp_i10 = 0 # 表示 i k=1 0
        dp_i11 = float("-inf") # 表示 i k=1 1
        dp_i20 = 0 # 表示 i k=2 0
        dp_i21 = float("-inf") # 表示 i k=2 1
        for i in range(n):
            dp_i20 = max(dp_i20, dp_i21 + prices[i])
            dp_i21 = max(dp_i21, dp_i10 - prices[i])
            dp_i10 = max(dp_i10, dp_i11 + prices[i])
            dp_i11 = max(dp_i11, -prices[i]) # 对照 k = 1时的dp[i][1]
        return dp_i20
"""
执行结果：通过 显示详情
执行用时：612 ms, 在所有 Python3 提交中击败了29.72%的用户
内存消耗：23.4 MB, 在所有 Python3 提交中击败了45.16%的用户
"""




"""
188

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

给定 k
"""

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        # 每次交易 股票的买入卖出至少需要2天 因此最多交易 n // 2 次
        # 当指定的 k 大于 n // 2 则相当于 k = 无穷
        n = len(prices)
        if n == 0: return 0
        if k > (n // 2): # k = inf 的情况
            dp_i_0 = 0
            dp_i_1 = -prices[0]
            
            for i in range(1, n):
                temp = dp_i_0
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])
                dp_i_1 = max(dp_i_1, temp - prices[i])
            return dp_i_0
        else:            
            # 指定 k 且 不是 inf
            dp = [[[0 for i in range(2)] for _k in range(k + 1)] for j in range(n)]
            for i in range(n):
                for _k in range(k, 0, -1):
                    if i == 0:
                        # base case
                        dp[i][_k][0] = 0
                        dp[i][_k][1] = -prices[i]
                        continue
                    # 状态转移方程
                    dp[i][_k][0] = max(dp[i - 1][_k][0], dp[i - 1][_k][1] + prices[i])
                    dp[i][_k][1] = max(dp[i - 1][_k][1], dp[i - 1][_k - 1][0] - prices[i])
            return dp[n - 1][k][0]
"""
执行结果：通过 显示详情
执行用时：232 ms, 在所有 Python3 提交中击败了10.98%的用户
内存消耗：24.6 MB, 在所有 Python3 提交中击败了7.82%的用户
"""         
























       