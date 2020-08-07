#include "normal.h"

/*
动态规划

我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。


*/

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i <= n; i++)
            dp[i][i] = 0;

        for (int j = 2; j <= n; j++) {
            for (int i = j - 1; i >= 1; i--) {
                for (int k = i + 1; k <= j - 1; k++)
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));   // 所有的比较选最小的，左右比较选较大的
                dp[i][j] = min(dp[i][j], min(i + dp[i + 1][j], dp[i][j - 1] + j));
            }
        }

        return dp[1][n];
    }
};