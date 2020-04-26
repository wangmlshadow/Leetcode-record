#include "normal.h"

/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一
个重复的整数。假设只有一个重复的整数，找出这个重复的数。

说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   
public:
    int findDuplicate(vector<int>& nums) {
        int cnt = nums.size();

        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++)
                if (nums[i] == nums[j])
                    return nums[i];
        }

        return 0;
    }
};
