#include "normal.h"

/*
动态规划

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所
需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回?-1。


*/

class Solution {  // 超时
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res;
        getRes(coins, amount, 0, res);

        if (res.empty())
            return -1;

        return *min_element(res.begin(), res.end());
    }

    void getRes(vector<int>& coins, int amount, int cnt, vector<int>& res) {
        if (amount == 0)
            res.push_back(cnt);

        if (amount < 0)
            return;

        for (auto n : coins) {
            getRes(coins, amount - n, cnt + 1, res);
        }
    }
};

class Solution {   // 空间换时间   还是超时
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;

        map<int, int> have;
        return solution(coins, amount, have);
    }

    int solution(vector<int>& coins, int amount, map<int, int>& have) {
        if (amount < 0)
            return -1;

        if (amount == 0)
            return 0;

        if (have.find(amount) != have.end() && have[amount] != -1)
            return have[amount];

        int minVal = INT_MAX;

        for (auto coin : coins) {
            int res = solution(coins, amount - coin, have);

            if (res >= 0 && res < minVal)
                minVal = 1 + res;
        }

        have[amount] = (minVal == INT_MAX) ? -1 : minVal;
        return have[amount];
    }
};


class Solution {  // 超时
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;

        have = vector<int>(amount + 1, -1);
        return solution(coins, amount);
    }

private:
    vector<int> have;
    int solution(vector<int>& coins, int amount) {
        if (amount < 0)
            return -1;

        if (amount == 0)
            return 0;

        if (have[amount] != -1)
            return have[amount];

        int minVal = INT_MAX;

        for (auto coin : coins) {
            int res = solution(coins, amount - coin);

            if (res >= 0 && res < minVal)
                minVal = 1 + res;
        }

        have[amount] = (minVal == INT_MAX) ? -1 : minVal;
        return have[amount];
    }
};

class Solution {  // dp
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            } 
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};