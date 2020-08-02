#include "normal.h"

/*
动态规划

硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几
种表示法。(结果可能会很大，你需要将结果模上1000000007)
*/

class Solution {
public:
    int waysToChange(int n) { 
        const int mod = 1000000007;
        vector<int> dp(n + 1, 0);
        vector<int> coins = {25, 10, 5, 1};
        dp[0] = 1;

        for (int i = 0; i < 4; i++) {
            int coin = coins[i];

            for (int j = coin; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - coin]) % mod;
            }
        }

        return dp[n];
    }
};
