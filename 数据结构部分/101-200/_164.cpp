#include "normal.h"

/*
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。


你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
*/


class Solution {   // 可以通过
public:
    int maximumGap(vector<int>& nums) {
        // 不考虑线性时间复杂度
        int size = nums.size();

        if (size < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];

        for (int i = 2; i < size; i++) {
            if (nums[i] - nums[i - 1] > res)
                res = nums[i] - nums[i - 1];
        }

        return res;
    }
};



class Solution {    // 桶和鸽笼原理
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();

        if (size < 2)
            return 0;

        int minVal = nums[0];
        int maxVal = nums[0];

        for (int i = 1; i < size; i++) {
            if (nums[i] < minVal)
                minVal = nums[i];
            
            if (nums[i] > maxVal)
                maxVal = nums[i];
        }

        if (minVal == maxVal)
            return 0;

        int gap = (maxVal - minVal + size - 1) / (size - 1);

        vector<int> mins(size - 1, maxVal);
        vector<int> maxs(size - 1, minVal);

        for (int i = 0; i < size; i++) {
            if (nums[i] == minVal || nums[i] == maxVal)
                continue;

            int index = (nums[i] - minVal) / gap;

            if (nums[i] < mins[index])
                mins[index] = nums[i];

            if (nums[i] > maxs[index])
                maxs[index] = nums[i];
        }

        int res = 0;
        int preMax = minVal;

        for (int i = 0; i < size - 1; i++) {
            if (mins[i] == maxVal)
                continue;

            res = max(res, mins[i] - preMax);
            preMax = maxs[i];
        }

        return max(res, maxVal - preMax);
    }
};

