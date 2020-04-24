#include "normal.h"

/*
给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二
元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        string track = "";
        size = num.size();
        backtrack(num, target, 0, 0, 1, track);
        return res;
    }

private:
    vector<string> res;
    int size;

    void backtrack(string& num, int& target, int index, long val, long mult, string& track) {   // mult 上一步运算时右边的操作数
        if (index == size) {
            if (val == target)
                res.push_back(track);
            return;
        }
        
        int len = track.size();

        for (int i = index; i < size; i++) {
            string sVal = num.substr(index, i - index + 1);
            long n = stol(sVal);

            if (index == 0) {
                track += sVal;
                backtrack(num, target, i + 1, n, n, track);
                track.resize(len);
            }
            else {
                track += "+" + sVal;
                backtrack(num, target, i + 1, val + n, n, track);
                track.resize(len);

                track += "-" + sVal;
                backtrack(num, target, i + 1, val - n, -n, track);  // -n 统一了加减
                track.resize(len);

                track += "*" + sVal;
                backtrack(num, target, i + 1, val - mult + mult * n, mult * n, track);
                track.resize(len);
            }

            if (n == 0)  // 除了0之外 没有01 02 以0开头的数
                return;
        }            
    }
};
