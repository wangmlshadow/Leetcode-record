#include "normal.h"

/*
数组

平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi]。请你计算访问所有这些点需要的最小时间（以秒为单位）。

你可以按照下面的规则在平面上移动：

每一秒沿水平或者竖直方向移动一个单位长度，或者跨过对角线（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
必须按照数组中出现的顺序来访问这些点。

思路：两点之间的移动秒数/次数 = 两点横纵坐标之间差值的较大值
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 1; i < points.size(); i++) {
            res += (max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1])));
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：12 ms, 在所有 C++ 提交中击败了85.08%的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/