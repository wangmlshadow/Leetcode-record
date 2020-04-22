#include "normal.h"

/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> s;
        int cnt = nums.size();

        if (cnt == 0)
            return {};

        for (int i = 0; i < cnt; i++) {
            if (s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                s.erase(nums[i]);
        }

        vector<int> res;
        res.push_back(*s.begin());
        res.push_back(*s.rbegin());
        return res;
    }
};