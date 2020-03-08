#include "normal.h"

/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();

        if (m == 0)
            return;

        int n = matrix[0].size();

        // 标记第一行第一列是否有元素为0
        bool row = false;
        bool col = false;
        
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }               
        }
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
         
        for (int i = 1; i < n; i++)
            if (matrix[0][i] == 0)
                for (int j = 1; j < m; j++)
                    matrix[j][i] = 0;

        if (row)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;

        if (col)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;        
    }
};