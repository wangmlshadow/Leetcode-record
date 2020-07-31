#include "normal.h"

/*
动态规划

给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网
格，并返回该子网格中的元素数量。如果不存在，则返回 0。

思路：依次遍历数组，寻找将点i,j 作为正方形的左上角顶点，并符合条件的正方形
      注意下面代码中为了减少计算次数做出的优化
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows == 0 ? 0 : grid[0].size();

        if (rows * cols == 0)
            return 0;

        int res = 0;   // 记录正方形边长

        for (int i = 0; i < rows - res; i++) {
            for (int j = 0; j < cols - res; j++) {
                if (grid[i][j] == 0)
                    continue;

                res = max(res, 1);
                int maxCnt = 1;

                while (i + maxCnt < rows && j + maxCnt < cols && grid[i + maxCnt][j] == 1 && grid[i][j + maxCnt] == 1)
                    maxCnt++;

                if (res >= maxCnt)  // 减少不需要的运算
                    continue;

                int cnt = 1;
                

                while (cnt < maxCnt) {
                    bool end = true;   // 表明是否还可以组成符合条件的正方形
                    // 行，列
                    for (int col = j + 1; col <= j + cnt; col++) {
                        if (grid[i + cnt][col] == 0) {
                            end = false;
                            break;
                        }
                    }

                    for (int row = i + 1; row <= i + cnt; row++) {
                        if (grid[row][j + cnt] == 0) {
                            end = false;
                            break;
                        }
                    }

                    if (end)
                        res = max(res, cnt + 1);

                    cnt++;
                }
            }
        }

        return res * res;
    }
};


/*
执行结果：通过 显示详情
执行用时：32 ms, 在所有 C++ 提交中击败了68.27%的用户
内存消耗：10 MB, 在所有 C++ 提交中击败了95.12%的用户
*/
