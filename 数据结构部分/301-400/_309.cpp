#include "normal.h"

/*

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i_0 = 0, i_1 = INT_MIN, i_pre = 0;

        for (int i = 0; i < n; i++) {
            int temp = i_0;
            i_0 = max(i_0, i_1 + prices[i]);
            i_1 = max(i_1, i_pre - prices[i]);
            i_pre = temp;
        }

        return i_0;
    }
};