#include "normal.h"

/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;

        // 对26取余
        while (n > 26) {
            int i = (n - 1) % 26;
            res.push_back('A' + i);
            n = (n - 1) / 26;
        }
        
        if (n != 0)
            res.push_back('A' + n - 1);

        reverse(res.begin(), res.end());

        return res;
    }
};

/*
执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/