#include "normal.h"

/*
数组

给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

思路：从前向后扫描，寻找递增序列
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int res = 1, cur = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                cur++;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }

        return max(res, cur);
    }
};

/*
执行结果：通过 显示详情
执行用时：24 ms, 在所有 C++ 提交中击败了40.53%的用户
内存消耗：10.8 MB, 在所有 C++ 提交中击败了6.67%的用户
*/