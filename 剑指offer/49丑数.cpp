/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
*/

// x 是堆中最小的丑数，由于 2x, 3x, 5x2x,3x,5x 也是丑数
class Solution {
public:
    int nthUglyNumber(int n) {
        long res;
        set<long> nums;
        nums.insert(1);
        while (n != 0) {
            res = *nums.begin();
            nums.insert(res * 2);
            nums.insert(res * 3);
            nums.insert(res * 5);
            nums.erase(res);
            --n;
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：128 ms, 在所有 C++ 提交中击败了12.88%的用户
内存消耗：29 MB, 在所有 C++ 提交中击败了17.31%的用户
*/