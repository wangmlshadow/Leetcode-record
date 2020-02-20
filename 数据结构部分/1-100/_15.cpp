#include "normal.h"

/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());

        int left, right, i;

        for (i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;

            left = i + 1;
            right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    left++;
                    right--;
                }
            }

            while (i < nums.size() - 2 && nums[i + 1] == nums[i])
                i++;
        }

        return result;
    }
};