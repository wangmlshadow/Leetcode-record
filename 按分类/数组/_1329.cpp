#include "normal.h"

/*
数组

给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。

思路：一个个对角线进行排序 重新赋值
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = rows == 0 ? 0 : mat[0].size();

        if (rows * cols == 0 || rows == 1 || cols == 1)
            return mat;

        //vector<vector<int>> res(mat);

        // 对角线起始点从 [0][0] -> [rows - 2][0]
        for (int i = 0; i < rows - 1; i++) {
            vector<int> temp;
            for (int row = i, col = 0; row < rows && col < cols; row++, col++) {
                temp.push_back(mat[row][col]);
            }

            sort(temp.begin(), temp.end());

            for (int row = i, col = 0, j = 0; row < rows && col < cols; row++, col++, j++) {
                mat[row][col] = temp[j];
            }
        }

        // 对角线起始点从[0][cols - 2] -> [0][1]
        for (int i = cols - 2; i > 0; i--) {
            vector<int> temp;
            for (int row = 0, col = i; row < rows && col < cols; row++, col++) {
                temp.push_back(mat[row][col]);
            }

            sort(temp.begin(), temp.end());

            for (int row = 0, col = i, j = 0; row < rows && col < cols; row++, col++, j++) {
                mat[row][col] = temp[j];
            }
        }

        return mat;
    }
};

/*
执行结果：通过 显示详情
执行用时：28 ms, 在所有 C++ 提交中击败了50.44%的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/