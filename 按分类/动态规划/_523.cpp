#include "normal.h"

/*
动态规划

给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子
数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

数组的长度不会超过 10,000 。
你可以认为所有数字总和在 32 位有符号整数范围内。

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = -1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (k != 0)
                sum %= k;

            if (m.find(sum) != m.end()) {
                if (i - m[sum] > 1)
                    return true;
            }
            else
                m[sum] = i;
        }

        return false;
    }
};