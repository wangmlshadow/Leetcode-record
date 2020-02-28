#include "normal.h"

/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {     // 有点慢
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        string result;
        int len_1 = num1.length();
        //int len_2 = num2.length();
        string str_2 = num2;

        for (int i = 0; i < len_1; i++) {
            int temp = num1[len_1 - 1 - i] - '0';           

            for (int j = 0; j < temp; j++) {
                result = plus(result, str_2);
            }
            str_2.push_back('0');
        }

        return result;
    }

    string plus(string num1, string num2) {
        int len_1 = num1.length();
        int len_2 = num2.length();
        int ex = 0;
        int temp_1 = 0;
        int i;
        string result;

        for (i = 0; i < len_1 && i < len_2; i++) {
            temp_1 = ex + (int)(num1[len_1 - 1 - i] - '0') + (int)(num2[len_2 - 1 -i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
        }

        while (i < len_1) {
            temp_1 = ex + (int)(num1[len_1 - 1 - i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
            i++;
        }

        while (i < len_2) {
            temp_1 = ex + (int)(num2[len_2 - 1 - i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
            i++;
        }

        if (ex != 0)
            result.push_back((char)('0' + ex));

        int len_3 = result.length();
        for (int j = 0; j < len_3 / 2; j++) {
            char ch = result[j];
            result[j] = result[len_3 - 1 - j];
            result[len_3 - 1 - j] = ch;
        }

        return result;
    }
};


class Solution {     // 优化上面的解决方案，主要优化第二个for语句
public:              // 运行结果显示运行时间是上述方案的四分之一，运行内存是上述方案的一半，但还是比较慢啊
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        string result;
        int len_1 = num1.length();
        //int len_2 = num2.length();
        string str_2 = num2;

        for (int i = 0; i < len_1; i++) {
            int temp = num1[len_1 - 1 - i] - '0';

            result = plus(result, mlt(str_2, temp));
            
            str_2.push_back('0');
        }

        return result;
    }

    string plus(string num1, string num2) {
        int len_1 = num1.length();
        int len_2 = num2.length();
        int ex = 0;
        int temp_1 = 0;
        int i;
        string result;

        for (i = 0; i < len_1 && i < len_2; i++) {
            temp_1 = ex + (int)(num1[len_1 - 1 - i] - '0') + (int)(num2[len_2 - 1 - i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
        }

        while (i < len_1) {
            temp_1 = ex + (int)(num1[len_1 - 1 - i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
            i++;
        }

        while (i < len_2) {
            temp_1 = ex + (int)(num2[len_2 - 1 - i] - '0');
            ex = temp_1 / 10;
            temp_1 = temp_1 - 10 * ex;
            result.push_back((char)('0' + temp_1));
            i++;
        }

        if (ex != 0)
            result.push_back((char)('0' + ex));

        int len_3 = result.length();
        for (int j = 0; j < len_3 / 2; j++) {
            char ch = result[j];
            result[j] = result[len_3 - 1 - j];
            result[len_3 - 1 - j] = ch;
        }

        return result;
    }

    string mlt(string num1, int cnt) {   // 字符串表示的数字num1与仅有一位的数cnt相乘
        if (cnt == 0)
            return "0";

        int len = num1.length();
        int ex = 0;
        string result;

        for (int i = 0; i < len; i++) {
            int temp_1 = num1[len - 1 - i] - '0';
            int temp_2 = ex + cnt * temp_1;
            ex = temp_2 / 10;
            temp_2 = temp_2 - ex * 10;
            result.push_back((char)('0' + temp_2));
        }

        if (ex != 0)
            result.push_back((char)('0' + ex));

        int len_3 = result.length();
        for (int j = 0; j < len_3 / 2; j++) {
            char ch = result[j];
            result[j] = result[len_3 - 1 - j];
            result[len_3 - 1 - j] = ch;
        }

        return result;
    }
};