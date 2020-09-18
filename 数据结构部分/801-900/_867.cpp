#include "normal.h"

/*
数组

给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

思路：i,j -> j,i
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = rows == 0 ? 0 : A[0].size();

        if (rows * cols == 0)
            return A;

        vector<vector<int>> res(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[j][i] = A[i][j];
            }
        }

        return res;
    }
};

/*
执行结果：通过显示详情
执行用时：24 ms, 在所有 C++ 提交中击败了34.24%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了71.24%的用户
*/