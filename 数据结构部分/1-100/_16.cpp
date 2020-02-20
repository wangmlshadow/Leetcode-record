#include "normal.h"

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2], temp = 0;

        sort(nums.begin(), nums.end());

        int left, right, i;

        for (i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                temp = nums[i] + nums[left] + nums[right];
                result = (abs(target - result) < abs(target - temp)) ? result : temp;

                if (temp > target)
                    right--;
                else if (temp < target)
                    left++;
                else
                    return target;
            }
        }

        return result;
    }
};