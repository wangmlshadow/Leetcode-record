#include "normal.h"

/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = str.length();
        map<string, char> p;
        int j = 0;
        set<char> s;

        for (int i = 0; i < len; i++) {
            if (str[i] == ' ')
                continue;

            int pos = i;

            while (i < len && str[i] != ' ')
                i++;

            string cur = str.substr(pos, i - pos);

            if (p.find(cur) == p.end()) {
                if (s.find(pattern[j]) != s.end())
                    return false;
                s.insert(pattern[j]);
                p[cur] = pattern[j];
            }               
            else
                if (p[cur] != pattern[j])
                    return false;

            j++;
        }

        if (j != pattern.length())
            return false;

        return true;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
6.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/