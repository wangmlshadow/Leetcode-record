#include "normal.h"

/*
数组

给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。

思路：双指针法
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                res += leftMax - height[left++];
                leftMax = max(leftMax, height[left]);
            }
            else {
                res += rightMax - height[right--];
                rightMax = max(rightMax, height[right]);
            }
        }

        return res;
    }
};
