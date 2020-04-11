#include "normal.h"

/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        if (k == 0)
            return;

        vector<int> helper;

        for (int i = size - k; i < size; i++)
            helper.push_back(nums[i]);

        for (int i = size - 1; i >= k; i--)
            nums[i] = nums[i - k];

        for (int i = 0; i < k; i++)
            nums[i] = helper[i];
    }
};

// 还可以使用三次反转