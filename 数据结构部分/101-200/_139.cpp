#include "normal.h"

/*

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
*/

class Solution {   // 递归超时
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        len = s.length();

        if (len == 0)
            return true;

        return solution(s, 0, 1, wordDict);
    }
private:
    int len;

    bool solution(string& s, int begin, int cnt, vector<string>& wordDict) {
        if (begin + cnt == len) {
            vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(begin, cnt));

            return key != wordDict.end();
        }
        else if (begin + cnt < len) {
            vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(begin, cnt));

            if (key == wordDict.end())
                return solution(s, begin, cnt + 1, wordDict);
            else
                return solution(s, begin + cnt, 1, wordDict) || solution(s, begin, cnt + 1, wordDict);
        }
        else
            return false;
    }
};

// 试试动态规划     结果可以通过 没有超时
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {   // 已知两者非空 但是测试用例有为空的。。。
        int len = s.length();
        int size = wordDict.size();

        if (size == 0)
            return len == 0;

        int maxLen = wordDict[0].length();
        int minLen = wordDict[0].length();

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

        return dp[len - 1];
    }
};