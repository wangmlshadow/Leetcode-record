#include "normal.h"

/*
数组

给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。


思路：使用vector<int> ap(26, 0);作为引用。记录chars中每个字母个数，用于查找是否每个word都可以拼写出来
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> ap(26, 0);

        for (int i = 0; i < chars.length(); i++) {
            ap[chars[i] - 'a']++;
        }

        int res = 0;

        for (int i = 0; i < words.size(); i++) {
            vector<int> temp(ap);
            int j;

            for (j = 0; j < words[i].size(); j++) {
                if (--temp[words[i][j] - 'a'] < 0) {  // 每用去一个字母，计数值减一 
                    break;
                }
            }

            if (j == words[i].length())
                res += words[i].length();
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：100 ms, 在所有 C++ 提交中击败了82.94%的用户
内存消耗：19.3 MB, 在所有 C++ 提交中击败了80.00%的用户
*/