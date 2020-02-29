#include "normal.h"

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int pos = 0;
        int end = nums.size() - 1;

        if (end == 0)
            return 0;

        for (int i = 0; i <= end; ) {
            if (pos + nums[i] >= end) {
                return ++step;
            }

            int max = 1;
            for (int j = 2; j <= nums[i]; j++) {     // 寻找本次跳跃距离加上下次跳跃距离的最大值
                if (max + nums[i + max] < j + nums[i + j])
                    max = j;
            }

            i += max;
            pos = i;
            step++;
        }

        return step;
    }
};