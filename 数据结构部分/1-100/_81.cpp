#include "normal.h"

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;

        this->target = target;

        return search_1(nums, 0, nums.size() - 1);
    }
private:
    int target;

    bool search_1(vector<int>& nums, int left, int right) {    // 在排好序但经过旋转的数组中查找
        if (left > right)
            return false;
        else if (left == right)
            return target == nums[left];
        else {
            while (left < right && nums[left] == nums[right])
                left++;

            if (left == right)
                return target == nums[left];
        }

        while (left < right && nums[left + 1] == nums[left])
            left++;

        while (right > left&& nums[right - 1] == nums[right])
            right--;

        if (left == right)
            return target == nums[left];

        if (target == nums[left] || target == nums[right])
            return true;

        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return true;
        else if (nums[mid] > target) {
            if (nums[mid] < nums[left]) {
                return search_1(nums, left + 1, mid - 1);
            }
            else {
                if (target > nums[left])
                    return search_2(nums, left + 1, mid - 1);
                else
                    return search_1(nums, mid + 1, right - 1);
            }
        }
        else {
            if (nums[mid] < nums[left]) {
                if (target > nums[left])
                    return search_1(nums, left + 1, mid - 1);
                else
                    return search_2(nums, mid + 1, right - 1);
            }
            else
                return search_1(nums, mid + 1, right - 1);
        }

        return false;
    }

    bool search_2(vector<int>& nums, int left, int right) {     // 在排好序未旋转的数组中查找
        if (left > right)
            return false;

        if (nums[left] == target || nums[right] == target)
            return true;

        while (left < right && nums[left + 1] == nums[left])
            left++;

        while (right > left&& nums[right - 1] == nums[right])
            right--;

        if (left == right)
            return false;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target) {
                while (mid > left&& nums[mid - 1] == nums[mid])
                    mid--;

                right = mid - 1;
            }
            else {
                while (mid < right && nums[mid + 1] == nums[mid])
                    mid++;

                left = mid + 1;
            }
        }

        return false;
    }
};