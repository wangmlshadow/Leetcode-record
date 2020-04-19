#include "normal.h"

/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int cnt = nums.size();
        vector<string> res;

        if (cnt == 0)
            return res;

        int left = 0;
        int right = 0;

        for (int i = 1; i < cnt; i++) {
            if (nums[i] == nums[right] + 1)
                right++;
            else {
                if (left == right) {
                    res.push_back(to_string(nums[left]));
                }
                else {
                    res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }

                left = i;
                right = i;
            }
        }

        if (left == right) {
            res.push_back(to_string(nums[left]));
        }
        else {
            res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }

        return res;
    }
};