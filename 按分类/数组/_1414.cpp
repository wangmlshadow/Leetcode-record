#include "normal.h"

/*
数组

给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

思路：使用数组按顺序保存所有小于k的斐波拉契数列 每次将k减去一个最接近他的斐波拉契数值 直到k==0
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {       
        if (k < 3)
            return 1;

        vector<int> fb(2, 1);
        int a = 1, b = 1;

        while (a + b <= k) {
            fb.push_back(a + b);
            a = b;
            b = *fb.rbegin();
        }

        int res = 0, index = fb.size() - 1;

        while (k != 0) {
            if (fb[index] <= k) {
                res++;
                k -= fb[index];
            }
            else
                index--;
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了76.85%的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/