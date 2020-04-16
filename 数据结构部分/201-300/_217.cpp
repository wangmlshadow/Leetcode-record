#include "normal.h"

/*
给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> helper;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            set<int>::iterator iter = helper.find(nums[i]);

            if (iter != helper.end())
                return true;
            else
                helper.insert(nums[i]);
        }
        
        return false;
    }
};