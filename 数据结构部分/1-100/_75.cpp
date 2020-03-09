#include "normal.h"

/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {   // 运行速度超过100%
        int size = nums.size();
        int left = -1, right = size;
        int i = 0;

        while (i < right) {
            if (nums[i] == 0) {
                if (i == left + 1) {
                    left++;
                    i++;
                }
                else {
                    nums[i] = nums[++left];
                    nums[left] = 0;
                }
            }
            else if (nums[i] == 1) {
                i++;
            }
            else {
                nums[i] = nums[right - 1];
                nums[--right] = 2;
            }
        }
    }
};