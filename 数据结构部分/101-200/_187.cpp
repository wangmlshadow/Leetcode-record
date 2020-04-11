#include "normal.h"

/*
所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。

输出重复出现的长度为10的子序列 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-dna-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> helper;
        set<string> have;
        vector<string> res;
        int len = s.length();
        for (int i = 0; i < len - 9; i++) {
            string curSub = s.substr(i, 10);

            if (helper.find(curSub) != helper.end())
                have.insert(curSub);
            else
                helper.insert(curSub);
        }

        for (set<string>::iterator iter = have.begin(); iter != have.end(); iter++)
            res.push_back(*iter);

        return res;
    }
};