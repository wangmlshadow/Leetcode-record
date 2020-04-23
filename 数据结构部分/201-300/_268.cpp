#include "normal.h"

/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        long long cnt = nums.size();

        for (int i = 0; i < cnt; i++) {
            sum += nums[i];
        }

        return ((1 + cnt) * cnt) / 2 - sum;
    }
};