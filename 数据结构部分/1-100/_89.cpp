#include "normal.h"

/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 从n - 1 可以推导到 n， 从0到n
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        int head = 1;

        for (int i = 0; i < n; i++) {
            for (int j = result.size() - 1; j >= 0; j--) 
                result.push_back(result[j] + head);

            head <<= 1;
        }

        return result;
    }
};