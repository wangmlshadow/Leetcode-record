#include "normal.h"

/*
数组

假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻
的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

思路：计算总共可插入的1的最大数，注意首尾两端的处理 数组越界

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxC = 0;
        int end = flowerbed.size() - 1;

        if ((flowerbed.size() == 1 && flowerbed[0] == 0) || (flowerbed.size() > 1 && flowerbed[0] == 0 && flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            maxC++;
        }

        for (int i = 1; i < end; i++) {
            if (flowerbed[i] == 1) {
                i++;
            }
            else {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    i++;
                    maxC++;
                }
            }
        }

        if (end - 1 >= 0 && flowerbed[end - 1] == 0 && flowerbed[end] == 0) {
            flowerbed[end] = 1;
            maxC++;
        }

        return maxC >= n;
    }
};

/*
执行结果：通过 显示详情
执行用时：52 ms, 在所有 C++ 提交中击败了14.46%的用户
内存消耗：19.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/