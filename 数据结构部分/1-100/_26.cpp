#include "normal.h"

/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int cnt = 1;
        int ahead = nums[0], cur = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (ahead != nums[i]) {
                nums[cur] = nums[i];
                ahead = nums[i];
                cur++;
                cnt++;
            }
        }

        return cnt;
    }
};