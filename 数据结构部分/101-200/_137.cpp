#include "normal.h"

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 使用了额外空间也能通过
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> helper;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            map<int, int>::iterator key = helper.find(nums[i]);

            if (key == helper.end())
                helper[nums[i]] = 1;
            else {
                if (helper[nums[i]] == 1)
                    helper[nums[i]] = 2;
                else
                    helper.erase(key);
            }
        }

        return helper.begin()->first;
    }
};

// 位运算
