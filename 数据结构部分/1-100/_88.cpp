#include "normal.h"

/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < m; i++)
            nums1[m + n - 1 - i] = nums1[m - 1 - i];

        int pos_1 = n, pos_2 = 0, cnt = 0;

        while (pos_2 < n) {
            if (pos_1 < m + n) {
                if (nums1[pos_1] < nums2[pos_2])
                    nums1[cnt++] = nums1[pos_1++];
                else
                    nums1[cnt++] = nums2[pos_2++];
            }
            else
                nums1[cnt++] = nums2[pos_2++];
        }
    }
};