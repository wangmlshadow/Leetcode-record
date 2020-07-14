#include "normal.h"

/*
数组

给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向
上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

思路：使用递归确定每个独立小岛的面积，为了避免重复计算，将扫描过的1变为2

*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows == 0 ? 0 : grid[0].size();

        if (rows * cols == 0)  // grid为空
            return 0;

        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // 你可以假设 grid 的四个边缘都被 0（代表水）包围着。
                    // bool sign = true;    // 标记是否可以构成岛屿   理解错了 不需要全部被0包围的才算岛屿
                    int cur = 0;
                    getThisArea(i, j, grid, cur);
                    res = max(res, cur);
                }
            }
        }

        return res;
    }

    void getThisArea(int row, int col, vector<vector<int>>& grid, int& cur) { 
        // if (!sign)
        //     return;     不需要在发现构不成岛屿后立即返回，需要将这一块连起来的但却构不成岛屿的1变成2 

        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {   // 到了边界
        //    sign = false;
            return;
        }

        if (grid[row][col] == 0 || grid[row][col] == 2)  // 非陆地---0  已被扫描过---2 
            return;

        cur++;
        grid[row][col] = 2;
        getThisArea(row - 1, col, grid, cur);
        getThisArea(row + 1, col, grid, cur);
        getThisArea(row, col - 1, grid, cur);
        getThisArea(row, col + 1, grid, cur);
    }
};

/*
执行结果：通过 显示详情
执行用时：36 ms, 在所有 C++ 提交中击败了46.66%的用户
内存消耗：22.3 MB, 在所有 C++ 提交中击败了16.67%的用户
*/