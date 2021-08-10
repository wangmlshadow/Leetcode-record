/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。
*/

// n0 - n9 10
// n10 - n99 90
// n100 - n999 900
// ...           9000
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        long cnt = 9;
        int len = 2, times = 90, allTimes = 90; // 长度为len的数字出现times次
        int num = 10; // 此次出现的数字

        while (cnt < n) {
            if (cnt + len >= n) {
                int res = stoi(string(1, to_string(num)[n - cnt - 1]));
                return res;
            }
            cnt += len;
            ++num;
            --times;
            if (times == 0) {
                ++len;
                allTimes *= 10;
                times = allTimes;
            }
        }

        return 0;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：920 ms, 在所有 C++ 提交中击败了12.74%的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了51.40%的用户
*/

class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        long cnt = 9;
        long len = 2, times = 90, allTimes = 90; // 长度为len的数字出现times次
        long num = 10; // 此次出现的数字

        while (cnt < n) {
            if (n > cnt + len * allTimes) {
                num += allTimes;
                cnt += len * allTimes;
                ++len;
                allTimes *= 10;
                times = allTimes;
            }
            else {   // n 在 长度为len的所有数之间
                // 计算出n为长度为len的数的第几个
                int temp1 = n - cnt;
                
                int temp2 = temp1 / len;  
                int temp3 = temp1 % len;   

                if (temp3 == 0) {   // 第temp1个数的最后一位
                    int res = stoi(string(1, to_string(num + temp2 - 1)[len - 1]));
                    return res;
                }
                else {   // 第temp1 + 1个数的temp3位
                    int res = stoi(string(1, to_string(num + temp2)[temp3 - 1]));
                    return res;
                }
            }
        }

        return 0;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了58.86%的用户
*/