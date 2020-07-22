#include "normal.h"

/*
数组

给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。

思路：从后往前依次替换 使用rep保存此时的最大值，也是用于替换的值
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty())
            return arr;

        int rep = arr[arr.size() - 1];   // 用于替换的数
        arr[arr.size() - 1] = -1;

        for (int i = arr.size() - 2; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rep;
            rep = max(rep, temp);
        }

        return arr;
    }
};

/*
执行结果：通过 显示详情
执行用时：36 ms, 在所有 C++ 提交中击败了39.34%的用户
内存消耗：14 MB, 在所有 C++ 提交中击败了7.14%的用户
*/