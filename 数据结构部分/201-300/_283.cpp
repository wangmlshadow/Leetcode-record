#include "normal.h"

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int cnt = nums.size();

        for (int i = 0; i < cnt; i++) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }

        for (; cur < cnt; cur++)
            nums[cur] = 0;
    }
};