#include "normal.h"

/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int _numRows = (numRows < s.length()) ? numRows : s.length();

        if (_numRows == 1 || _numRows == 0)   // 注意此处，若所给字符串为空时，若所给行数为1时
            return s;

        vector<string> substr(_numRows);
        int i = 0;
        int row = 0;
        bool plus = true;
        while (i < s.length()) {
            substr[row].push_back(s[i]);
            i++;
            if (plus) {
                row++;
                if (row == _numRows - 1) {
                    plus = false;
                }
            }
            else {
                row--;
                if (row == 0) {
                    plus = true;
                }
            }
        }

        for (int j = 1; j < _numRows; j++)
            substr[0] = substr[0] + substr[j];

        return substr[0];
    }
};
