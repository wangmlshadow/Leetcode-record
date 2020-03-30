# include "normal.h"

/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 不验证是否能拆分就会超时 验证了就不超时
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.length();
        size = wordDict.size();

        if (size == 0 || len == 0)
            return {};

        vector<string> res;
        maxLen = wordDict[0].length();
        minLen = wordDict[0].length();

        for (int i = 1; i < size; i++) {
            if (maxLen < wordDict[i].length())
                maxLen = wordDict[i].length();

            if (minLen > wordDict[i].length())
                minLen = wordDict[i].length();
        }


        vector<vector<bool>> helper(len, vector<bool>(len, false));  // helper[i][j]判断s的子串i-j是否再wordDict中出现

        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                int subLen = j - i + 1;

                if (subLen < minLen || subLen > maxLen)
                    continue;
                else {
                    vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(i, subLen));
                    helper[i][j] = key != wordDict.end();
                }
            }
        }

        vector<bool> dp(len, false);

        for (int i = 0; i < len; i++) {
            if (i == 0) {
                dp[i] = helper[i][i];
                continue;
            }

            bool sign = helper[0][i];

            for (int j = 0; j <= i; j++) {
                sign = sign || (dp[j] && helper[j + 1][i]);

                if (sign)
                    break;
            }

            dp[i] = sign;
        }

        if (!dp[len - 1])  // 验证是否能拆分
            return {};

        addRes(helper, s, 0, minLen, "", res);
        return res;
    }

private:
    int len;
    int size;
    int maxLen;
    int minLen;

    void addRes(vector<vector<bool>>& helper, string& s, int begin, int cnt, string one, vector<string>& res) {
        if (cnt > maxLen)
            return;

        if (begin + cnt == len) {
            if (helper[begin][begin + cnt - 1])
                res.push_back(one + s.substr(begin, cnt));

            return;
        }
        else if (begin + cnt > len)
            return;
        else {
            if (helper[begin][begin + cnt - 1]) {
                addRes(helper, s, begin + cnt, minLen, one + s.substr(begin, cnt) + " ", res);
            }
            addRes(helper, s, begin, cnt + 1, one, res);
        }
    }
};