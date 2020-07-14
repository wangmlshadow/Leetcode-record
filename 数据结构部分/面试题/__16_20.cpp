#include "normal.h"

/*
数组
 
在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字
映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张
含有有效单词的列表。映射如下图所示：

思路：依次剔除不符合要求的单词
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {      
        if (num.find('1') != num.npos || num.find('0') != num.npos)  // 包含数字1 或者数字0 是不能组成有效单词的
            return vector<string>();

        vector<string> res(words);

        for (int i = 0; i < num.length(); i++) {
            if (res.empty())
                return res;

            vector<string> cur;
            int n = num[i] - '0';

            for (int j = 0; j < res.size(); j++) {
                if (res[j].length() <= i)
                    continue;

                if (matched(n, res[j][i]))
                    cur.push_back(res[j]);
            }

            res = cur;
        }

        return res;
    }

    bool matched(int n, char ch) {
        if (n == 2) {
            if (ch == 'a' || ch == 'b' || ch == 'c')
                return true;
            else
                return false;
        }

        if (n == 3) {
            if (ch == 'd' || ch == 'e' || ch == 'f')
                return true;
            else
                return false;
        }

        if (n == 4) {
            if (ch == 'g' || ch == 'h' || ch == 'i')
                return true;
            else
                return false;
        }

        if (n == 5) {
            if (ch == 'j' || ch == 'k' || ch == 'l')
                return true;
            else
                return false;
        }

        if (n == 6) {
            if (ch == 'm' || ch == 'n' || ch == 'o')
                return true;
            else
                return false;
        }

        if (n == 7) {
            if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's')
                return true;
            else
                return false;
        }

        if (n == 8) {
            if (ch == 't' || ch == 'u' || ch == 'v')
                return true;
            else
                return false;
        }

        if (n == 9) {
            if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z')
                return true;
            else
                return false;
        }

        return false;
    }
};

/*
执行结果：通过 显示详情
执行用时：208 ms, 在所有 C++ 提交中击败了7.98%的用户
内存消耗：235.6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/