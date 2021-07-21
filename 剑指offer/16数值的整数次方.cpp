/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同
时不需要考虑大数问题。
*/
// 一直乘下去 超时 需要优化
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double res = 1;
        while (n > 0) {
            res *= x;
            --n;
        }
        return res;
    }
};

// 辅助存储 二分思想
class Solution {
public:
    double myPow(double x, int n) {
        long cnt = n;// 最小的负数 int 转为正数 溢出
        if (cnt == 0) {
            return 1;
        }
        if (cnt < 0) {
            cnt = -cnt;
            x = 1 / x;
        }
        map<int, double> resMap;
        resMap[0] = 1.0;
        resMap[1] = x;        
        return getRes(resMap, cnt);
    }

    double getRes(map<int, double>& resMap, long n) {
        if (n == 0 || n == 1) {
            return resMap[n];
        }
        if (resMap.count(n) != 0) {
            return resMap[n];
        }
        resMap[n] = getRes(resMap, n / 2) * getRes(resMap, n - n / 2);
        return resMap[n];
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了37.24%的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了5.30%的用户
*/