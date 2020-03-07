#include "normal.h"

/*

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int plus = 0;
        int len_1 = a.length();
        int len_2 = b.length();
        int pos = 0;
        string result;

        while (plus == 1 || pos < len_1 || pos < len_2) {
            if (pos < len_1 && pos < len_2) {
                if (a[len_1 - 1 - pos] == '1') {
                    if (b[len_2 -1 -pos] == '1') {
                        if (plus == 1) {
                            result.push_back('1');
                        }
                        else {
                            plus = 1;
                            result.push_back('0');
                        }
                    }
                    else {
                        if (plus == 1) {
                            result.push_back('0');
                        }
                        else {
                            result.push_back('1');
                        }
                    }
                }
                else {
                    if (b[len_2 - 1 - pos] == '1') {
                        if (plus == 1) {
                            result.push_back('0');
                        }
                        else {
                            result.push_back('1');
                        }
                    }
                    else {
                        if (plus == 1) {
                            result.push_back('1');
                            plus = 0;
                        }
                        else {
                            result.push_back('0');
                        }
                    }
                }
            }
            else if (pos < len_1 && pos >= len_2) {
                if (a[len_1 - 1 - pos] == '1') {
                    if (plus == 1) {
                        result.push_back('0');
                    }
                    else {
                        result.push_back('1');
                    }
                }
                else {
                    if (plus == 1) {
                        result.push_back('1');
                        plus = 0;
                    }
                    else {
                        result.push_back('0');
                    }
                }
            }
            else if (pos >= len_1 && pos < len_2) {
                if (b[len_2 - 1 - pos] == '1') {
                    if (plus == 1) {
                        result.push_back('0');
                    }
                    else {
                        result.push_back('1');
                    }
                }
                else {
                    if (plus == 1) {
                        result.push_back('1');
                        plus = 0;
                    }
                    else {
                        result.push_back('0');
                    }
                }
            }
            else {
                result.push_back('1');
                plus = 0;
            }

            pos++;
        }

        int len = result.length();

        for (int i = 0; i < len / 2; i++) {
            char ch = result[i];
            result[i] = result[len - 1 - i];
            result[len - 1 - i] = ch;
        }

        return result;
    }
};