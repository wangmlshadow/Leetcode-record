#include "normal.h"

/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int sign = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                sign++;
                break;
            }
        }

        if (sign == 0)   // 没有1
            return 1;

        if (size == 1)   // 经过上一个if判断出有1，但nums中仅有一个元素
            return 2;

        // 将所有负数和0，以及大于size的数变为1
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0 || nums[i] > size)
                nums[i] = 1;
        }

        // 要求辅助空间为O(1)，利用数组本身的存储空间
        for (int i = 0; i < size; i++) {
            int temp = abs(nums[i]);

            if (temp == size)
                nums[0] = -abs(nums[0]);
            else
                nums[temp] = -abs(nums[temp]);
        }

        for (int i = 1; i < size; i++) {
            if (nums[i] > 0)
                return i;
        }

        if (nums[0] > 0)
            return size;         // nums为1.....n-1
        else
            return size + 1;     // nums为1.......n
    }
};