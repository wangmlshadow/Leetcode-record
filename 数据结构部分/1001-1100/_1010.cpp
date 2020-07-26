#include "normal.h"

/*
数组

在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

思路：1.双重循环 暴力破解 结果超时
      2.记录所有数对60取余的结果，两余数和为60则满足条件，注意余数为0 / 30 的情况
*/


class Solution {    // 超时
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;

        for (int i = 0; i < time.size(); i++) {
            for (int j = i + 1; j < time.size(); j++) {
                if ((time[i] + time[j]) % 60 == 0)
                    res++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mod(60, 0);
        int res = 0;

        for (int i = 0; i < time.size(); i++) {
            mod[time[i] % 60]++;
        }

        if (mod[0] > 1)
            res = mod[0] * (mod[0] - 1) / 2;

        for (int i = 1; i < 30; i++)
            res += mod[i] + mod[60 - i];

        if (mod[30] > 1)
            res += mod[30] * (mod[30] - 1) / 2;

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：36 ms, 在所有 C++ 提交中击败了42.18%的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/