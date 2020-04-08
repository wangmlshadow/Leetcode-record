#include "normal.h"

/*
给定一个整数 n，返回 n! 结果尾数中零的数量。
*/

class Solution {
public:
    int trailingZeroes(int n) {
        long num = 1;   // 测试用例超出了这个范围

        while (n > 0)
            num = num * n--;

        string str = to_string(num);
        int len = str.length(), cnt = 0;

        for (int i = len - 1; i >= 0; i--) {
            if (str[i] == '0')
                cnt++;
            else
                break;
        }            

        return cnt;
    }
};



class Solution {  // 结果中尾数的0的数量 观察阶乘计算时有没有10 100等
public:
    int trailingZeroes(int n) {
        // 10 5 2
        vector<int> helper(3, 0);  // 记录10 5 2 的个数
        int cnt = 0;   // 记录尾数中0的数量 其实就是阶乘中可以拆出来几个10

        for (int i = 2; i <= n; i++) {   // 还是超时了
            int val = i;

            if (val >= 10) {
                while (val % 10 == 0) {
                    helper[0]++;
                    val = val / 10;
                }
            }

            if (val >= 5) {
                while (val % 5 == 0) {
                    helper[1]++;
                    val = val / 5;
                }
            }

            if (val >= 2) {
                while (val % 2 == 0) {
                    helper[2]++;
                    val = val / 2;
                }
            }
        }

        cnt = helper[0] + min(helper[1], helper[2]);

        return cnt;
    }
};


class Solution {
public:
    int trailingZeroes(int n) {   // 2出现的比5多 只需要计算5的个数
        int cnt = 0;

        while (n >= 5) {
            n = n / 5;
            cnt += n;            
        }

        return cnt;
    }
};