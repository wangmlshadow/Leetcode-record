#include "normal.h"

/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味
着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一
晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
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

        vector<int> dp_1(size, 0);
        dp_1[0] = nums[0];
        dp_1[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < size - 1; i++) {
            dp_1[i] = max(dp_1[i - 1], dp_1[i - 2] + nums[i]);
        }

        vector<int> dp_2(size, 0);
        dp_2[size - 1] = nums[size - 1];
        dp_2[size - 2] = max(nums[size - 1], nums[size - 2]);

        for (int i = size - 3; i > 0; i--) {
            dp_2[i] = max(dp_2[i + 1], dp_2[i + 2] + nums[i]);
        }

        return max(dp_1[size - 2], dp_2[1]);
    }
};

/*
执行用时 :
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
