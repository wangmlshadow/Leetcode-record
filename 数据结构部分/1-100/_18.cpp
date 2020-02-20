#include "normal.h"

/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
找出所有满足条件且不重复的四元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        if (nums.size() < 4)
            return result;

        int i, j, left, right;

        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size() - 3; i++) {
            for (j = i + 1; j < nums.size() - 2; j++) {
                left = j + 1;
                right = nums.size() - 1;

                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                    }
                }

                while (j < nums.size() - 2 && nums[j] == nums[j + 1])
                    j++;
            }

            while (i < nums.size() - 3 && nums[i] == nums[i + 1])
                i++;
        }

        return result;
    }
};