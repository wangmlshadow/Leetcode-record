#include "normal.h"

/*
数组

给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

思路：滑动窗口
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0, nowSum = 0;

        if (k > nums.size())
            return 0;

        for (int i = 0; i < k; i++) {
            nowSum += nums[i];
        }
        
        maxSum = nowSum;

        for (int i = k; i < nums.size(); i++) {
            nowSum += (nums[i] - nums[i - k]);
            maxSum = max(maxSum, nowSum);
        }

        return maxSum / double(k);
    }
};

/*
执行结果：通过 显示详情
执行用时：292 ms, 在所有 C++ 提交中击败了74.32%的用户
内存消耗：71.5 MB, 在所有 C++ 提交中击败了25.00%的用户
*/