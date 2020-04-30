#include "normal.h"

/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int cnt = nums.size();

        if (cnt == 0)
            return 0;

        vector<int> dp(cnt, 1);
        
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};