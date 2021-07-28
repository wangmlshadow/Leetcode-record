/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>();
        }
        vector<int> res;
        int left_row = 0, left_clo = 0, right_row = matrix.size() - 1, right_clo = matrix[0].size() - 1;
        while (left_row <= right_row && left_clo <= right_clo) {
            // 遍历 上 右 下 左
            for (int i = left_clo; i <= right_clo; ++i) {
                res.push_back(matrix[left_row][i]);
            }
            for (int i = left_row + 1; i <= right_row; ++i) {
                res.push_back(matrix[i][right_clo]);
            }
            for (int i = right_clo - 1; left_row < right_row && i >= left_clo; --i) {
                res.push_back(matrix[right_row][i]);
            }
            for (int i = right_row - 1; left_clo < right_clo && i > left_row; --i) {
                res.push_back(matrix[i][left_clo]);
            }
            ++left_row;
            ++left_clo;
            --right_row;
            --right_clo;
        }
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了93.39%的用户
内存消耗：9.6 MB, 在所有 C++ 提交中击败了73.96%的用户
*/