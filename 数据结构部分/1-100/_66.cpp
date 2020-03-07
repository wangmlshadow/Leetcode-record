#include "normal.h"

/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int plus = 1;
        int i;

        for (i = digits.size() - 1; i >= 0; i--) {
            plus += digits[i];

            if (plus > 9) {
                result.push_back(plus % 10);
                plus = 1;
            }
            else {
                result.push_back(plus);
                plus = 0;
            }
        }

        if (plus == 1) {
            result.push_back(plus);
        }

        int len = result.size();
        for (i = 0; i < len / 2; i++) {
            int temp = result[i];
            result[i] = result[len - 1 - i];
            result[len - 1 - i] = temp;
        }

        return result;
    }
};