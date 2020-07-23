#include "normal.h"

/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt = nums.size();
        vector<int> res;
        map<int, int> helper;

        for (int i = 0; i < cnt; i++)
            helper[nums[i]]++;

        for (map<int, int>::iterator iter = helper.begin(); iter != helper.end(); iter++)
            if (iter->second > (cnt / 3))
                res.push_back(iter->first);

        return res;
    }
};

class Solution {   // 摩尔投票法 超过三分之一的元素
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt = nums.size();
        vector<int> res;
        int val1 = INT_MAX, val2 = INT_MIN;   // val1 val2搞一样的话有个案例不通过
        int k1 = 0, k2 = 0;

        for (int i = 0; i < cnt; i++) {
            if (val1 == nums[i]) {
                k1++;
                continue;
            }

            if (val2 == nums[i]) {
                k2++;
                continue;
            }

            if (k1 == 0) {
                val1 = nums[i];
                k1 = 1;
                continue;
            }

            if (k2 == 0) {
                val2 = nums[i];
                k2 = 1;
                continue;
            }

            k1--;
            k2--;
        }
        
        k1 = 0;
        k2 = 0;

        for (int i = 0; i < cnt; i++) {
            if (val1 == nums[i])
                k1++;

            if (val2 == nums[i])
                k2++;
        }

        if (k1 > cnt / 3)
            res.push_back(val1);

        if (k2 > cnt / 3)
            res.push_back(val2);

        return res;
    }
};