#include "normal.h"

/*

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。
*/

class Solution {    // 使用set 利用set的特性 其内不存在重复值
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int size = nums.size();
        set<int> con;
        
        for (auto num : nums)
            con.insert(num);

        int maxCnt = 0;

        for (auto num : nums) {
            if (con.find(num - 1) == con.end()) {   // 连续数组的最小值开始搜索 避免多次对同一个连续数组进行搜索
                int cur = num;
                int cnt = 1;

                while (con.find(++num) != con.end())
                    cnt++;

                maxCnt = max(maxCnt, cnt);
            }
        }
            
        return maxCnt;
    }
};