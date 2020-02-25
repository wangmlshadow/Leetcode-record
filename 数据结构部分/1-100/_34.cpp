#include "normal.h"

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result({ -1, -1 });

        if (nums.empty())
            return result;

        int left = 0, right = nums.size() - 1, mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) {
                int i = mid, j = mid;

                while (i - 1 >= 0 && nums[i - 1] == target)
                    i--;

                while (j + 1 < nums.size() && nums[j + 1] == target)
                    j++;

                result[0] = i;
                result[1] = j;

                break;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return result;
    }
};