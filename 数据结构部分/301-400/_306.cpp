#include "normal.h"

/*
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        len = num.length();

        if (len < 3)
            return false;

        sign = false;
        backtrack(num, 0, 0);
        return sign;
    }

private:
    vector<long double> res;
    int len;
    bool sign;

    void backtrack(string& num, int begin, int end) {
        if (sign)
            return;

        if (begin >= len && res.size() > 2) {
            sign = true;
            return;
        }

        for (int i = end; i < len; i++) {
            long double cur = toNum(num, begin, i);

            if (cur == -1)
                break;

            if (res.size() >= 2) {
                long double a = res[res.size() - 2];
                long double b = res[res.size() - 1];

                if (a + b > cur)
                    continue;

                if (a + b < cur)
                    return;
            }
            
            res.push_back(cur);
            backtrack(num, i + 1, i + 1);

            if (sign)
                return;
            else {
                res.pop_back();
            }            
        }
    }

    long double toNum(string& num, int begin, int end) {
        if (num[begin] == '0' && end != begin)
            return -1;

        long double cur = 0;

        for (; begin <= end; begin++)
            cur = cur * 10 + num[begin] - '0';

        return cur;
    }
};