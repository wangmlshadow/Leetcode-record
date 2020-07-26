#include "normal.h"


/*
数组

给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。

请你统计并返回 grid 中 负数 的数目。

思路：对grid每一行做二分操作，寻找每一行负数的起始位置
*/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows == 0 ? 0 : grid[0].size();

        if (rows * cols == 0 || grid[rows - 1][cols - 1] >= 0)
            return 0;

        int res = 0, left, right;
        // 每一行做一个二分
        for (int row = 0; row < rows; row++) {
            left = 0;
            right = cols - 1;
            while (left <= right) {
                int mid = (left + right) / 2;

                if (grid[row][mid] >= 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            res += (cols - left);
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：16 ms, 在所有 C++ 提交中击败了87.16%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/