#include "normal.h"

/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {   // 一圈一圈的遍历
        vector<int> result;
        int m = matrix.size();

        if (m == 0)
            return result;

        int n = matrix[0].size();

        // 每一圈的左上角和右下角
        int r1 = 0, c1 = 0;
        int r2 = m - 1, c2 = n - 1;

        while (r1 <= r2 && c1 <= c2) {
            for (int i = c1; i <= c2; i++)
                result.push_back(matrix[r1][i]);

            for (int i = r1 + 1; i <= r2; i++)
                result.push_back(matrix[i][c2]);

            if (r1 < r2 && c1 < c2) {
                for (int i = c2 - 1; i >= c1; i--)
                    result.push_back(matrix[r2][i]);

                for (int i = r2 - 1; i > r1; i--)
                    result.push_back(matrix[i][c1]);
            }

            r1++;
            c1++;
            r2--;
            c2--;
        }

        return result;
    }
};