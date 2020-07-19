#include "normal.h"

/*
给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。

请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
*/

class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int minV = INT_MAX, maxV = INT_MIN;

        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];

            if (salary[i] < minV)
                minV = salary[i];

            if (salary[i] > maxV)
                maxV = salary[i];
        }

        sum = sum - minV - maxV;
        double cnt = salary.size() - 2;

        return sum / cnt;
    }
};

/*
执行结果：通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了48.36%的用户
内存消耗：7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/