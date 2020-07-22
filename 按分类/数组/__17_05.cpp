#include "normal.h"

/*
数组

给定一个放有字符和数字的数组，找到最长的子数组，且包含的字符和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点最小的。若不存在这样的数组，返回一个空数组。
*/

class Solution {    // 可行 但是超时
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int size = array.size();
        vector<vector<int>> cnts(size + 1, vector<int>(2, 0));  // cnts[n + 1]记录array中前n个字符中数字、字符的数量

        for (int i = 0; i < size; i++) {
            if (isdigit(array[i][0])) {
                cnts[i + 1][0] = cnts[i][0] + 1;
                cnts[i + 1][1] = cnts[i][1];
            }
            else {
                cnts[i + 1][0] = cnts[i][0];
                cnts[i + 1][1] = cnts[i][1] + 1;
            }
        }

        int resL = 0, maxLen = 0;

        for (int i = 0; i < size; i++) {
            for (int j = size - 1; j > i; j--) {
                if (cnts[j + 1][0] - cnts[i][0] == cnts[j + 1][1] - cnts[i][1]) {  // 字串 i-j
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        resL = i;
                    }
                    break;   // 以i开头符合条件的最长字串已经出来了 不需要继续内部这个循环
                }
            }
        }

        if (maxLen == 0) {
            return vector<string>();
        }

        vector<string> res;
        res.insert(res.end(), array.begin() + resL, array.begin() + resL + maxLen);
        return res;
    }
};

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<int> num(array.size() + 1, 0);

        for (int i = 0; i < array.size(); i++) {
            if (isdigit(array[i][0]))
                num[i + 1] = num[i] + 1;
            else
                num[i + 1] = num[i] - 1;
        }

        map<int, int> m;
        int ans = 0, start = 0, end = 0;

        for (int i = 1; i <= array.size(); i++) {
            if (num[i] != 0 && m[num[i]] == 0)
                m[num[i]] = i;
            else {
                if (ans < i - m[num[i]]) {
                    ans = i - m[num[i]];
                    start = m[num[i]] + 1;
                    end = i;
                }
            }
        }

        if (ans == 0)
            return vector<string>();

        vector<string> res;
        res.insert(res.end(), array.begin() + start - 1, array.begin() + end);
        return res;
    }
};