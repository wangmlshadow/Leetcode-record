/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照
从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整
数，判断数组中是否含有该整数。
*/

// 不考虑题目给的数组的特性 直接暴力循环 看看会不会超时
// 执行结果证明不仅没有超时 而且还挺快 真没想到
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 不需要在前面判断数组长度是否>0
        // for循环已经做到了 但是注意 这样写的话 for循环外层应该循环行 内层未列 
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 C++ 提交中击败了99.99%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了29.44%的用户
*/

// 从右上角到左下角
// 二维数组右下部分的数据比左上大
// 还不如暴力循环 这就很奇怪 是其他操作占的时间更多？？？？？
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = 0, clo = matrix[0].size() - 1;

        while (row >= 0 && row < matrix.size() && clo >= 0 && clo < matrix[0].size()) {
            if (matrix[row][clo] > target) {
                // 比target大 左移
                clo -= 1;
            }
            else if (matrix[row][clo] < target) {
                // 比target小 下移
                row += 1;
            }
            else {
                // 相等
                return true;
            }
        }

        return false;
    }
};

/*
执行结果：通过 显示详情 添加备注
执行用时：24 ms, 在所有 C++ 提交中击败了90.01%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了6.25%的用户
*/