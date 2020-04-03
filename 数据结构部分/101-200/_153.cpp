#include "normal.h"

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 试一下直接遍历所有 看看会不会超时   竟然没有超时 但是比较慢
public:
    int findMin(vector<int>& nums) {
        int minRes = INT_MAX;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (minRes > nums[i])
                minRes = nums[i];
        }

        return minRes;
    }
};


class Solution {    // 试试二分法
public:
    int findMin(vector<int>& nums) {   // 比顺序遍历快得多 运行速度顺序遍历>5% 此方法>87.7%
        int size = nums.size();
        int right = size - 1, left = 0;
        int minRes = min(nums[left], nums[right]);

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[left]) {
                left = mid + 1;

                if (left >= size)
                    break;                    
            }
            else {
                minRes = min(minRes, nums[mid]);
                right = mid - 1;

                if (right < 0)
                    break;
            }

            minRes = min(minRes, min(nums[left], nums[right]));

            if (nums[left] < nums[right])   // left到right段为顺序数组
                break;
        }

        return minRes;
    }
};