/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == mid) {
                left = mid + 1;
            }
            else {
                if (mid - 1 >= 0 && mid - 1 == nums[mid - 1]) {
                    res = mid;
                    break;
                }

                if (left == right) {
                    res = mid;
                    break;
                }
                right = mid;
            }
        }

        if (res == -1) {
            res = nums.size();
        }

        return res;
    }
};

/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 C++ 提交中击败了41.25%的用户
内存消耗：16.7 MB, 在所有 C++ 提交中击败了72.39%的用户
通过测试用例：122 / 122
*/