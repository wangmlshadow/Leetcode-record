# -*- coding: utf-8 -*-
"""
Created on Sun Sep 20 16:32:23 2020

@author: Administrator
"""

"""
零钱兑换 动态规划
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总
金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
"""

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 暴力破解 比较所有可能组成amount的情况，选取使用硬币最少的情况
        def dp(n):
            # base case
            if n == 0:
                return 0
            if n < 0:
                return -1
            # 求最小值
            res = float('INF')
            for coin in coins:
                subproblem = dp(n - coin)
                # 子问题无解时 continue
                if subproblem == -1:
                    continue
                res = min(res, 1 + subproblem)
            
            return res if res != float('INF') else -1
        
        return dp(amount)# 超时

    
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 使用带备忘录的递归
        memo = dict()
        def dp(n):
            # 通过备忘录避免重复计算
            if n in memo:
                return memo[n]            
            if n == 0:
                return 0           
            if n < 0:
                return -1
            res = float('INF')
            for coin in coins:
                subproblem = dp(n - coin)
                if subproblem == -1:
                    continue
                res = min(res, 1 + subproblem)
            
            # 将已得到的结果记录到备忘录中
            memo[n] = res if res != float('INF') else -1
            return memo[n]
        
        return dp(amount)
"""
执行结果：通过显示详情
执行用时：2280 ms, 在所有 Python3 提交中击败了9.30%的用户
内存消耗：42.4 MB, 在所有 Python3 提交中击败了8.75%的用户
"""            
        
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 动态规划
        if amount < 0:
            return -1
        dp = [float('INF')] * (amount + 1) # 所需硬币数量最多不会超过amount
        dp[0] = 0
        
        for i in range (amount + 1):
            for coin in coins:
                # 子问题无解 continue
                if (i - coin < 0): continue
                dp[i] = min(dp[i], 1 + dp[i - coin])
        return dp[amount] if dp[amount] != float('INF') else -1
"""
执行结果：通过显示详情
执行用时：1628 ms, 在所有 Python3 提交中击败了52.72%的用户
内存消耗：13.5 MB, 在所有 Python3 提交中击败了56.16%的用户
"""   
# 同样的算法实现 C++的执行时间只需要124ms     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        