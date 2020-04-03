#include "normal.h"

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 相比于上一题 可能存在重复元素 在上一题第二种方法的基础上修改
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int right = size - 1, left = 0;       

        while (left < right && nums[left] == nums[left + 1])
            left++;

        if (left == right)
            return nums[left];

        int minRes = min(nums[left], nums[right]);

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[left] < nums[mid]) {
                while (mid < right && nums[mid] == nums[mid + 1])
                    mid++;

                if (mid == right)
                    break;

                left = mid;
            }
            else if (nums[left] > nums[mid]) {
                right = mid;
            }
            else {
                while (mid > left && nums[mid] == nums[mid - 1])
                    mid--;

                if (mid == left)
                    break;
                right = mid - 1;
            }

            minRes = min(minRes, min(nums[left], nums[right]));

            if (nums[left] < nums[right])
                break;
        }

        return minRes;
    }
};