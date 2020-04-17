#include "normal.h"

/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = (rows == 0) ? 0 : matrix[0].size();

        if (rows == 0 || cols == 0)
            return 0;

        int maxSize = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    maxSize = max(maxSize, getThisSquare(i, j, matrix, rows, cols));
                }
            }
        }

        return maxSize;
    }

    int getThisSquare(int row, int col, vector<vector<char>>& matrix, int rows, int cols) {   // 以点row,col为左上角的最大正方形面积
        int maxSize = 1;
        int endR = row + 1, endC = col + 1;

        while (endR < rows && endC < cols) {
            for (int i = col; i <= endC; i++)
                if (matrix[endR][i] == '0')
                    return maxSize;

            for (int i = row; i < endR; i++)
                if (matrix[i][endC] == '0')
                    return maxSize;

            maxSize = (endR - row + 1) * (endC - col + 1);
            endR++;
            endC++;
        }

        return maxSize;
    }
};