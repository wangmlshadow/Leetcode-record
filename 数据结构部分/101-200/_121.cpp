#include "normal.h"

/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        if (size < 2)
            return 0;

        int min = prices[0];  // 记录前n天的最低价
        int res = prices[1] - min;   // 记录最大利润

        for (int i = 1; i < size; i++) {
            res = (prices[i] - min > res) ? prices[i] - min : res;
            min = (min > prices[i]) ? prices[i] : min;
        }
        
        if (res >= 0)
            return res;
        else
            return 0;
    }
};