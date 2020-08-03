#include "normal.h"

/*
动态规划

输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int tmp1 = nums[0], tmp2 = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            tmp1 = max(tmp1 + nums[i], nums[i]);
            tmp2 = max(tmp1, tmp2);
        }

        return tmp2;
    }
};

/*
执行结果：通过 显示详情
执行用时：48 ms, 在所有 C++ 提交中击败了77.19%的用户
内存消耗：23.1 MB, 在所有 C++ 提交中击败了44.80%的用户
*/