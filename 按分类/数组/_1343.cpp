#include "normal.h"

/*
1343. 大小为 K 且平均值大于等于阈值的子数组数目   数组
给你一个整数数组 arr 和两个整数 k 和 threshold 。

请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

思路：
    滑动窗口
    寻找均值大于等于threshold且长度为k的子数组，使用cur_sum存储此时正在操作的子数组的和     
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // 连续子数组 注意连续
        if (k > arr.size())
            return 0;

        int res = 0;
        long long sum = k * threshold, cur_sum = 0;
        int i = 0;

        for (; i < k; i++)
            cur_sum += arr[i];

        if (cur_sum >= sum)
            res++;

        for (; i < arr.size(); i++) {
            cur_sum = cur_sum - arr[i - k] + arr[i];  // 当前窗口所有元素的和等于前一个窗口和减去前一个窗口第一个元素，加上现在这个窗口最后一个值

            if (cur_sum >= sum)
                res++;
        }

        return res;
    }
};

/*
执行结果：
通过
显示详情
执行用时：188 ms, 在所有 C++ 提交中击败了94.68%的用户
内存消耗：52.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/