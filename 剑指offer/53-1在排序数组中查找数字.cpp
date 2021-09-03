/*
统计一个数字在排序数组中出现的次数。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < nums[mid]) {
                right = mid - 1;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                res = 1;
                int temp1 = mid - 1, temp2 = mid + 1;
                
                while (temp1 >= 0 && nums[temp1] == target) {
                    ++res;
                    --temp1;
                }
                while (temp2 < nums.size() && nums[temp2] == target) {
                    ++res;
                    ++temp2;
                }

                break;
            }
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了68.58%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了69.65%的用户
通过测试用例：88 / 88
*/