#include "normal.h"

/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直
到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> have;
        have.insert(n);

        while (n != 1) {
            int next = getNext(n);

            if (have.find(next) != have.end())
                return false;

            have.insert(next);
            n = next;
        }

        return true;
    }

    int getNext(int n) {
        int res = 0;

        while (n != 0) {
            res += (n % 10) * (n % 10);
            n = n / 10;
        }

        return res;
    }
};