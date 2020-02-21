#include "normal.h"

/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;

        int cur = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[cur] = nums[i];
                cur++;
            }
        }

        return cur;
    }
};

/*
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了13.11%的用户
*/