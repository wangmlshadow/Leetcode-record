#include "normal.h"

/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        vector<long> res;
        long a = numerator, b = denominator;
        string str;
        
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
            str += "-";

        a = abs(a); 
        b = abs(b);
        res.push_back(a / b);
        a = a % b * 10;

        vector<int> as;   // 查找重复点
        as.push_back(a);
        int pos = -1;

        while (a != 0) {
            long i = a / b;
            a = a % b * 10;
            res.push_back(i);

            for (int j = 0; j < as.size(); j++) {
                if (a == as[j]) {
                    pos = j + 1;
                    break;
                }
            }

            if (pos != -1)
                break;

            as.push_back(a);
        }

        int size = res.size();
        str += to_string(res[0]);

        if (size == 1)
            return str;

        str.push_back('.');

        for (int i = 1; i < size; i++) {
            if (i == pos)
                str.push_back('(');

            str += to_string(res[i]);
        }
        
        if (pos != -1)
            str.push_back(')');

        return str;
    }
};