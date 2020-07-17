#include "normal.h"

/*
绘制直线。有个单色屏幕存储在一个一维数组中，使得32个连续像素可以存放在一个 int 里。屏幕
宽度为w，且w可被32整除（即一个 int 不会分布在两行上），屏幕高度可由数组长度及屏幕宽度推
算得出。请实现一个函数，绘制从点(x1, y)到点(x2, y)的水平线。

给出数组的长度 length，宽度 w（以比特为单位）、直线开始位置 x1（比特为单位）、直线结束位
置 x2（比特为单位）、直线所在行数 y。返回绘制过后的数组。

思路：构造全为0的数组，计算直线起始位置和终止位置所造数学在数组中的位置 
注意：位置从0开始   转换为unsigned int
*/

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        int cnt = w / 32;
        int begin = y * cnt + x1 / 32;
        int end = y * cnt + x2 / 32;

        for (int i = begin; i <= end; i++)
            res[i] = -1;
        /*
        if (begin == end) {
            res[begin] = (unsigned int)res[begin] >> (x1 % 32 + 31 - x2 % 32);
            res[end] = (unsigned int)res[end] << (31 - x2 % 32);
        }
        else {
            res[begin] = (unsigned int)res[begin] >> (x1 % 32);
            res[end] = (unsigned int)res[end] << (31 - x2 % 32);
        }
        */
        res[begin] = (unsigned int)res[begin] >> (x1 % 32);
        res[end] = res[end] & ((unsigned int)(-1) << (31 - x2 % 32));

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了89.31%的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
*/