#include "normal.h"

/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {     // 将二维数组当作一维的，再用二分搜索
        int m = matrix.size();

        if (m == 0)
            return false;

        int n = matrix[0].size();

        int left = 1, right = m * n;

        while (left <= right) {
            int mid = (left + right) / 2;
            int row, col;

            if (mid % n == 0) {
                row = mid / n - 1;
                col = n - 1;
            }
            else {
                row = mid / n;
                col = mid - mid / n * n - 1;
            }

            int val = matrix[row][col];

            if (val == target)
                return true;
            else if (val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};