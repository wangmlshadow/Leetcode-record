#include "normal.h"

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

class Solution {     // 某一格所含与水量等于此格左右边界中较小值减去该格高度，双指针法，题目解析还介绍了其他三种方法
public:
    int trap(vector<int>& height) {
        int left = 0, right = 0;
        int left_id = 0, right_id = height.size() - 1;
        int total = 0;

        while (left_id < right_id) {
            if (height[left_id] <= height[right_id]) {
                if (left <= height[left_id])
                    left = height[left_id];
                else
                    total += (left - height[left_id]);

                left_id++;
            }
            else {
                if (right <= height[right_id])
                    right = height[right_id];
                else
                    total += (right - height[right_id]);

                right_id--;
            }
        }

        return total;
    }
};