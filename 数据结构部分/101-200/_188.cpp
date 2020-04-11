#include "normal.h"

/*

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {   // 运行不成功 没有足够内存分配 应该是k的原因
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // 股票交易次数从买入算起
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        } 

        return dp[cnt - 1][k][0];
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { // 但是现在超时了
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        if (k > cnt / 2)
            k = cnt / 2;   

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // 股票交易次数从买入算起
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[cnt - 1][k][0];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        if (k > cnt / 2) {
            int res = 0;

            for (int i = 0; i < cnt - 1; i++)
                if (prices[i + 1] > prices[i])
                    res += prices[i + 1] - prices[i];

            return res;
        }
        

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // 股票交易次数从买入算起
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[cnt - 1][k][0];
    }
};