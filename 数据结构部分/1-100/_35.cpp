#include "normal.h"

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int left = 0, right = nums.size() - 1, mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (left >= nums.size())
            return left;
        else {
            if (nums[left] > target)
                return left;
            else
                return left + 1;
        }
    }
};