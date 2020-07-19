#include "normal.h"

/*
数组

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

思路：1.最简单的，从每一位开始，测试由该位子作为子数组的起始位，是否可以得到和为k的连续子数组
      2.减少比较次数，可以使用类似于209题回头看的思路   出现负数如何解决？？？
      3.优化方法1
*/

class Solution {  // 此方法不行
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, left = 0, right = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum < k)
                continue;
            else if(sum > k) {
                while (sum >= k && left <= i) {
                    sum -= nums[left];
                    left++;

                    if (sum == k && left <= i) {  // 注意此处 可能出现符合条件的连续子数组   k为0的处理
                        res++;
                    }
                }
            }
            else {   // 从left到i的连续子数组和为k
                res++;
                sum -= nums[left];
                left++;
            }
        }

        return res;
    }
};



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<vector<long long>> sums(nums.size(), vector<long long>(nums.size(), 0));
        int res = 0;

        sums[0][0] = nums[0];

        if (sums[0][0] == k)
            res++;

        for (int i = 1; i < nums.size(); i++) {
            sums[0][i] = sums[0][i - 1] + nums[i];

            if (sums[0][i] == k)
                res++;
        }

        for (int i = 1; i < nums.size(); i++) {   // 超时
            for (int j = i; j < nums.size(); j++) {
                sums[i][j] = sums[i - 1][j] - nums[i - 1];

                if (sums[i][j] == k)
                    res++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   // 前缀和
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;

        for (auto& x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) res += mp[pre - k];
            mp[pre]++;
        }

        return res;
    }
};