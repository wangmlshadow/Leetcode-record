#include "normal.h"

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution { // 出错
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();


        int med = (nums1.size() + nums2.size() + 1) / 2;
        int cnt1 = 0;
        int cnt2 = 0;
        int median;
        
        for (int i = 1; i <= med; i++) {
            if (cnt1 < nums1.size() && cnt2 < nums2.size()) {
                if (nums1[cnt1] < nums2[cnt2]) {
                    median = nums1[cnt1];
                    cnt1++;
                }
                else {
                    median = nums2[cnt2];
                    cnt2++;
                }
            }
            else if (cnt1 < nums1.size() && cnt2 == nums2.size()) {
                median = nums1[cnt1];
                cnt1++;
            }
            else {
                median = nums2[cnt2];
                cnt2++;
            }
        }

        return median;
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();

        if (sum == 1) {
            if (nums1.size())
                return nums1[0];
            else
                return nums2[0];
        }

        int med = (nums1.size() + nums2.size() + 1) / 2;
        int cnt1 = 0;
        int cnt2 = 0;
        double n1, n2;

        for (int i = 1; i < med; i++) {
            if (cnt1 < nums1.size() && cnt2 < nums2.size()) {
                if (nums1[cnt1] < nums2[cnt2]) {
                    cnt1++;
                }
                else {
                    cnt2++;
                }
            }
            else if (cnt1 < nums1.size() && cnt2 == nums2.size()) {
                cnt1++;
            }
            else {
                cnt2++;
            }
        }

        if (cnt1 < nums1.size() && cnt2 < nums2.size()) {
            if (nums1[cnt1] < nums2[cnt2]) {
                n1 = nums1[cnt1];
                cnt1++;
            }
            else {
                n1 = nums2[cnt2];
                cnt2++;
            }
        }
        else if (cnt1 < nums1.size() && cnt2 == nums2.size()) {
            n1 = nums1[cnt1];
            cnt1++;
        }
        else {
            n1 = nums2[cnt2];
            cnt2++;
        }

        if (cnt1 < nums1.size() && cnt2 < nums2.size()) {
            if (nums1[cnt1] < nums2[cnt2]) {
                n2 = nums1[cnt1];
                cnt1++;
            }
            else {
                n2 = nums2[cnt2];
                cnt2++;
            }
        }
        else if (cnt1 < nums1.size() && cnt2 == nums2.size()) {
            n2 = nums1[cnt1];
            cnt1++;
        }
        else {
            n2 = nums2[cnt2];
            cnt2++;
        }

        if (sum % 2) {
            return n1;
        }
        else{
            return (n1 + n2) / 2;
        }
    }
};