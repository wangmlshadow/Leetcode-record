#include "normal.h"

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return nums[0];

        if (size == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            if (dp[i - 1] == dp[i - 2])
                dp[i] = dp[i - 1] + nums[i];
            else   // 表示nums[i - 1]被偷了
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};