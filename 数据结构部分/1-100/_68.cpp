#include "normal.h"

/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/text-justification
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {     // 执行速度击败100%
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int cntWords = words.size();
        vector<int> lenWords;

        for (int i = 0; i < cntWords; i++)
            lenWords.push_back(words[i].length());

        for (int i = 0; i < cntWords; i++) {
            int j;
            int curLen = lenWords[i];

            for (j = i + 1; j < cntWords; j++) {
                if (curLen + 1 + lenWords[j] <= maxWidth) {
                    curLen = curLen + 1 + lenWords[j];
                }
                else {
                    break;
                }
            }

            if (j == cntWords) {    // 单词全部用完
                string str = words[i];
                int cnt = lenWords[i];

                for (int k = i + 1; k < j; k++) {
                    str.push_back(' ');
                    str += words[k];
                    cnt = cnt + 1 + lenWords[k];
                }

                for (int m = cnt + 1; m <= maxWidth; m++)
                    str.push_back(' ');

                result.push_back(str);

                return result;
            }

            if (j == i + 1) {    // 这一行只有一个单词
                string str = words[i];

                for (int k = lenWords[i] + 1; k <= maxWidth; k++)
                    str.push_back(' ');

                result.push_back(str);
                continue;
            }

            // 这一行单词数不知一个
            int cnt_1 = j - i;    // 这一行中的单词数
            int cnt_2 = maxWidth - curLen + cnt_1 - 1;   // 空格数

            vector<int> temp(cnt_1 - 1, 0);   // 记录每个间隔中有多少的空格
            int curCnt = 0;

            for (int k = cnt_1 - 2; k >= 0; k--) {
                curCnt += cnt_2 / (k + 1);
                cnt_2 = cnt_2 % (k + 1);
                temp[k] = curCnt;
            }

            string str;
            for (int k = i; k < j - 1; k++) {
                str += words[k];

                for (int m = 0; m < temp[k - i]; m++)
                    str.push_back(' ');
            }
            
            str += words[j - 1];
            result.push_back(str);
            i = j - 1;
        }

        return result;
    }
};