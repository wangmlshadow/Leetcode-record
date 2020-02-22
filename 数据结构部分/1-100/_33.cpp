#include "normal.h"

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        return search_2(nums, target, 0, nums.size() - 1);
    }

    int search_2(vector<int>& nums, int& target, int left, int right) {    // 有序数组旋转后所得数组
        if (target == nums[left])
            return left;

        if (target == nums[right])
            return right;

        if (left >= right)
            return -1;

        if (right == left + 1)
            return -1;

        if (nums[left] < nums[right])
            return search_3(nums, target, left + 1, right - 1);

        int mid = (left + right) / 2;
        if (target > nums[left]) {
            if (nums[mid] < nums[left])
                return search_2(nums, target, left + 1, mid - 1);
            else {
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    return search_2(nums, target, mid + 1, right - 1);
                else
                    return search_3(nums, target, left + 1, mid - 1);
            }
        }
        else {
            if (nums[mid] > nums[left])
                return search_2(nums, target, mid + 1, right - 1);
            else {
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    return search_3(nums, target, mid + 1, right - 1);
                else
                    return search_2(nums, target, left + 1, mid - 1);
            }
        }
        return -1;
    }

    int search_3(vector<int>& nums, int& target, int left, int right) {    // 有序数组二分搜索
        if (target > nums[right] || target < nums[left])
            return -1;

        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;

    }
};

















class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        return search_2(nums, target, 0, nums.size() - 1);
    }

    int search_2(vector<int>& nums, int& target, int left, int right) {    // 有序数组旋转后所得数组
        if (target == nums[left])
            return left;

        if (target == nums[right])
            return right;

        if (left >= right)
            return -1;

        if (right == left + 1)
            return -1;

        if (nums[left] < nums[right])
            return search_3(nums, target, left + 1, right - 1);

        int mid = (left + right) / 2;

        if (target == nums[mid])
            return mid;
        else if (target > nums[mid]) {
            if (nums[mid] > nums[left])
                return search_2(nums, target, mid + 1, right - 1);
            else {
                if (target > nums[right])
                    return search_2(nums, target, left + 1, mid - 1);
                else
                    return search_3(nums, target, mid + 1, right - 1);
            }
        }
        else {
            if (nums[mid] > nums[left]) {
                if (target > nums[left])
                    return search_3(nums, target, left + 1, mid - 1);
                else
                    return search_2(nums, target, mid + 1, right - 1);
            }
            else
                return search_2(nums, target, left + 1, mid - 1);
        }
    }

    int search_3(vector<int>& nums, int& target, int left, int right) {    // 有序数组二分搜索
        if (target > nums[right] || target < nums[left])
            return -1;

        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};