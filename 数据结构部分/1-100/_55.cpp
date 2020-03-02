#include "normal.h"

/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {     // 若某个位置可以到达，即此位置之前的那些可到达的位置中至少一个表示的跳跃距离大于等于两个位置之间的距离
        int size = nums.size();
        vector<bool> sign(size, false);
        sign[0] = true;

        for (int i = 1; i < size; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (sign[j] && i - j <= nums[j]) {
                    sign[i] = true;
                    break;
                }
            }
        }

        return sign[size - 1];
    }
};