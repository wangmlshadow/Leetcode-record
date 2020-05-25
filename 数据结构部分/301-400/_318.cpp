#include "normal.h"

/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并
且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的
两个单词，返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // set 并集 超时
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        int cnt = words.size();
        int maxLen = 0;

        if (cnt < 2)
            return res;

        vector<set<char>> all(cnt);

        for (int i = 0; i < cnt; i++) {
            for (auto ch : words[i])
                all[i].insert(ch);
        }   

        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                vector<char> temp;
                set_intersection(all[i].begin(), all[i].end(), all[j].begin(), all[j].end(), inserter(temp, temp.begin()));

                if (temp.empty() && res < words[i].length() * words[j].length()) {
                    res = words[i].length() * words[j].length();
                }
            }
        }

        return res;
    }
};

class Solution {   // 位运算
public:
    int maxProduct(vector<string>& words) {
        int res = 0, cnt = words.size();

        if (cnt < 2)
            return res;

        vector<int> masks(cnt, 0);

        for (int i = 0; i < cnt; i++) {
            int bitmask = 0;

            for (auto ch : words[i]) {
                bitmask |= 1 << (ch - 'a');
            }

            masks[i] = bitmask;
        }

        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (((masks[i] & masks[j]) == 0) && res < words[i].length() * words[j].length()) {
                    res = words[i].length() * words[j].length();
                }
            }
        }

        return res;
    }
};