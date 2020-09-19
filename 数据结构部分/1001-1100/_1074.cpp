#include "normal.h"

/*
数组

给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

1 <= matrix.length <= 300
1 <= matrix[0].length <= 300
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8

1.暴力列举所有可能情况 超时
2.预处理

*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = rows == 0 ? 0 : matrix[0].size();

        if (rows * cols == 0)
            return 0;

        vector<vector<int>> sums(matrix);  // [x][y] 表示他所在这一列到他为止所有元素的和

        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                sums[r][c] += sums[r - 1][c];
            }
        }
        
        int res = 0;

        for (int sr = 0; sr < rows; sr++) {    
            for (int er = sr; er < rows; er++) {    // sr为起始行 er为终止行
                int total = 0;
                unordered_map<int, int> d;

                for (int c = 0; c < cols; c++) {
                    int pre = sr < 1 ? 0 : sums[sr - 1][c];
                    total += sums[er][c] - pre;   // total为子数组元素和  一列一列累加

                    if (total == target)
                        res++;

                    if (d.count(total - target))   // 子数组和为target情况 参考560
                        res += d[total - target];

                    d[total] += 1;    // 记录
                }
            }
        }
        
        return res;
    }
};
