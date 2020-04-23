#include "normal.h"

/*
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

说明:

1 是丑数。
n 不超过1690。
*/

class Solution {   // 超时
public:
    int nthUglyNumber(int n) {
        int res = 1;

        while (n != 0) {
            if (isUgly(res))
                n--;

            res++;
        }

        return res - 1;
    }

    bool isUgly(int num) {
        if (num <= 0)
            return false;

        int ex = num;

        while (ex % 2 == 0)
            ex /= 2;

        while (ex % 3 == 0)
            ex /= 3;

        while (ex % 5 == 0)
            ex /= 5;

        return ex == 1;
    }
};


class Solution {   // 动态规划
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int two = 0, three = 0, five = 0;

        for (int i = 1; i < n; i++) {
            int cur = min(res[two] * 2, min(res[three] * 3, res[five] * 5));
            res.push_back(cur);

            if (cur == res[two] * 2)
                two++;
            
            if (cur == res[three] * 3)
                three++;

            if (cur == res[five] * 5)
                five++;
        }

        return *res.rbegin();
    }
};