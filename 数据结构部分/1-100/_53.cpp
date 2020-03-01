#include "normal.h"

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        int temp_1 = nums[0], temp_2 = nums[0];

        for (int i = 1; i < size; i++) {
            temp_2 = max(nums[i], temp_2 + nums[i]);
            temp_1 = max(temp_1, temp_2);
        }

        return temp_1;
    }
};