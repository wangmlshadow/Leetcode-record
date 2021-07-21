/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：
若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格

小数（按顺序）可以分成以下几个部分：
（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字

整数（按顺序）可以分成以下几个部分：
（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
*/

// 按顺序将是数值的情况判断一遍
class Solution {
public:
    bool isNumber(string s) {
        if (s.length() <= 0) {
            return false;
        }
        // 去空格
        int left = 0, right = s.length() - 1;
        for ( ; left < s.length(); ++left) {
            if (s[left] != ' ') {
                break;
            }
        }
        for ( ; right >= 0; --right) {
            if (s[right] != ' ') {
                break;
            }
        }
        if (left > right) {
            return false;
        }
        // 正负号
        if (s[left] == '+' || s[left] == '-') {
            if (left == right) {// 只有正负号
                return false;
            }
            ++left;
        }
        // 数字
        bool leftNum = false;// 小数点左边是否有数字
        while (left <= right) {
            if (!isdigit(s[left])) {
                break;
            }
            leftNum = true;
            ++left;
        }
        if (left > right) {
            return true;
        }
        // 小数点
        bool rightNum = false;// 小数点右边是否有数字
        if (s[left] == '.') {
            ++left;
            while (left <= right) {
                if (!isdigit(s[left])) {
                    break;
                }
                rightNum = true;
                ++left;
            }    
        }
        // 排除数值中没有小数 或者 整数的情况
        if (!leftNum && !rightNum) {
            return false;
        }
        if (left > right) {
            return true;
        }
        if (s[left] == 'E' || s[left] == 'e') {            
            if (left == right) {// 只有E
                return false;
            }
            ++left;
            bool numFollowE = false;// E 后是否有整数
            if (s[left] == '+' || s[left] == '-') {
                if (left == right) {// 只有正负号
                    return false;
                }
                ++left;
            }
            while (left <= right) {
                if (!isdigit(s[left])) {
                    break;
                }
                numFollowE = true;
                ++left;
            }
            if (!numFollowE) {// E 后无整数
                return false;
            }
        }
        if (left > right) {
            return true;
        }
        return false;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了72.94%的用户
*/