#include "normal.h"

/*
数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度
最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        int minLen = INT_MAX;
        int start = 0;
        int end = -1;
        int val = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] >= s)
                return 1;

            val += nums[i];
            end++;

            if (val < s) {
                continue;
            }
            else {
                minLen = min(minLen, end - start + 1);                
                val -= nums[start];
                start++;

                while (val >= s) {
                    minLen = min(minLen, end - start + 1);
                    val -= nums[start];
                    start++;
                }

                if (minLen == 2) {
                    for (int j = i + 1; j < size; j++) {
                        if (nums[j] >= s)
                            return 1;
                    }
                    return 2;
                }
            }
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};