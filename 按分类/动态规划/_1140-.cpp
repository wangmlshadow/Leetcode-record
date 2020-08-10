#include "normal.h"

/*
动态规划

亚历克斯和李继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。

亚历克斯和李轮流进行，亚历克斯先开始。最初，M = 1。

在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。

游戏一直持续到所有石子都被拿走。

假设亚历克斯和李都发挥出最佳水平，返回亚历克斯可以得到的最大数量的石头。

*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() + 1, 0));
        int sum = 0;

        for (int i = piles.size() - 1; i >= 0; i--) {
            sum += piles[i];

            for (int M = 1; M <= piles.size(); M++) {
                if (i + 2 * M >= piles.size())
                    dp[i][M] = sum;
                else {
                    for (int x = 1; x <= 2 * M; x++)
                        dp[i][M] = max(dp[i][M], sum - dp[i + x][max(M, x)]);
                }
            }
        }

        return dp[0][1];
    }
};

/*
执行结果：通过 显示详情
执行用时：12 ms, 在所有 C++ 提交中击败了58.71%的用户
内存消耗：7.3 MB, 在所有 C++ 提交中击败了85.29%的用户
*/