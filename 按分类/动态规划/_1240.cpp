#include "normal.h"

/*
你是一位施工队的工长，根据设计师的要求准备为一套设计风格独特的房子进行室内装修。

房子的客厅大小为 n x m，为保持极简的风格，需要使用尽可能少的 正方形 瓷砖来铺盖地面。

假设正方形瓷砖的规格不限，边长都是整数。

请你帮设计师计算一下，最少需要用到多少块方形瓷砖？

1 <= n <= 13
1 <= m <= 13

https://leetcode-cn.com/problems/tiling-a-rectangle-with-the-fewest-squares/solution/dp-by-aegeaner/
*/

class Solution {   
public:
    int tilingRectangle(int n, int m) {
        vector<vector<int>> dp(14, vector<int>(14, INT_MAX));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {   // 矩形长宽分别为i,j
            for (int j = 1; j <= m; j++) {
                if (i == j) {  // 已经是正方形
                    dp[i][j] = 1;
                    continue;
                }

                for (int r = 1; r <= i / 2; r++)  // 分为上下两个矩形
                    dp[i][j] = min(dp[i][j], dp[r][j] + dp[i - r][j]);

                for (int c = 1; c <= j / 2; c++)  // 分为左右两个矩形
                    dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j - c]);

                for (int p = 1; p <= i; p++) {  // 一个矩形分为五个矩形
                    for (int q = 1; q <= j; q++) {
                        dp[i][j] = min(dp[i][j], 1 + dp[p - 1][q] + dp[i - p + 1][q - 1] + dp[i - p][j - q + 1] + dp[p][j - q]);
                    }
                }
            }
        }

        return dp[n][m];
    }
};

/*
执行结果：通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了71.79%的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了31.82%的用户
*/