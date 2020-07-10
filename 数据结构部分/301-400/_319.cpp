#include "normal.h"

/*
初始时有 n 个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。 第 3 轮，每
三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。第 i 轮，每 i 个灯泡切换一次开关。 对于
第 n 轮，你只切换最后一个灯泡的开关。 找出 n 轮后有多少个亮着的灯泡。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 超时
public:
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;

        vector<bool> bulb(n, true);

        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j < n; j += i) {
                bulb[j] = !bulb[j];
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++)
            if (bulb[i])
                res++;

        return res;
    }
};

class Solution {  // 开关被操作奇数次后灯泡是亮着的，平方数的因数个数是奇数，因为因数成对出现

public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};