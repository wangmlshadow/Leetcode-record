#include "normal.h"

/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
*/

class Solution { // 错误 需要考虑负值
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        if (size == 1)
            return nums[0];

        int maxRes = nums[0];
        int cur = nums[0];

        for (int i = 1; i < size; i++) {
            cur = max(nums[i], nums[i] * cur);
            maxRes = max(cur, maxRes);
        }

        return maxRes;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxRes = INT_MIN;
        int imax = 1, imin = 1;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] < 0)
                swap(imax, imin);

            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            maxRes = max(maxRes, imax);
        }

        return maxRes;
    }
};