#include "normal.h"

/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 特别快，但花费内存也多
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = nums.size();

        if (cnt < 2)
            return;

        int i;

        for (i = cnt - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1])
                break;
        }

        if (i == 0) {
            for (i = 0; i < cnt / 2; i++) {
                int temp = nums[i];
                nums[i] = nums[cnt - i - 1];
                nums[cnt - i - 1] = temp;
            }

            return;
        }

        int pos = i - 1;   // 需要被修改的开始位置
        int k = i++;

        for (; i < nums.size(); i++) {
            if (nums[i] > nums[pos] && nums[i] < nums[k])
                k = i;
        }

        int temp = nums[pos];
        nums[pos] = nums[k];
        nums[k] = temp;

        sort(nums.begin() + pos + 1, nums.end());

        return;
    }
};

