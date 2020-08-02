#include "normal.h"

/*
动态规划

给定一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

思路：1.使用map统计每个num有多少个，然后动态规划，即循环内的if else
      2.不使用map，而是使用vector,vector中元素个数为nums.max - nums.min + 1，动态规划时不需要else

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;

        map<int, int> all;   // key:val  ->  num:cnt

        for (auto num : nums)
            all[num]++;

        vector<int> dp(all.size() + 1, 0);
        map<int, int>::iterator iter = all.begin();
        dp[1] = iter->first * iter->second;
        int i = 2, pre = iter->first;
        iter++;

        for ( ; iter != all.end(); iter++, i++) {
            if (pre == iter->first - 1)
                dp[i] = max(dp[i - 1], dp[i - 2] + iter->first * iter->second);
            else
                dp[i] = dp[i - 1] + iter->first * iter->second;

            pre = iter->first;
        }

        return *dp.rbegin();
    }
};

/*
执行结果：通过 显示详情
执行用时：16 ms, 在所有 C++ 提交中击败了49.34%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了38.18%的用户
*/