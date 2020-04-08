#include "normal.h"

/*
给定一个Excel表格中的列名称，返回其相应的列序号。
*/

class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        int len = s.length();
        long cnt = 1;

        for (int i = len - 1; i >= 0; i--) {
            int cur = s[i] - 'A' + 1;
            res = res + cur * cnt;
            cnt = cnt * 26;
        }

        return res;
    }
};

/*
执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/