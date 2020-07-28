#include "normal.h"

/*
数组

给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。

更正式地，检查是否存在两个下标 i 和 j 满足：

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

思路：1.使用set，注意单独处理0
      2.暴力法，双重循环
      3.排序，双指针
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> myS;
        int cntZero = 0;

        for (int num : arr)
            if (num != 0)
                myS.insert(num);
            else
                cntZero++;

        if (cntZero >= 2)
            return true;

        for (int num : arr) {
            if (myS.find(num * 2) != myS.end())
                return true;
        }

        return false;
    }
};

/*
执行结果：通过 显示详情
执行用时：16 ms, 在所有 C++ 提交中击败了20.52%的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/