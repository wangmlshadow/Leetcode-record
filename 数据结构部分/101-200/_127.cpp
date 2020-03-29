#include "normal.h"

/*

给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
            return 0;

        queue<item> save;
        unordered_map<string, int> allSave;
        //unordered_map<string, vector<string>> reflex;
        bool findEnd = false;
        save.push(item(beginWord, 1));
        allSave.insert(pair<string, int>(beginWord, 1));
        int size = wordList.size();

        while (!save.empty()) {
            item now = save.front();
            save.pop();

            if (now.str == endWord) {
                return allSave[endWord];
            }

            for (int i = 0; i < size; i++) {
                if (match(now.str, wordList[i])) {
                    if (allSave.find(wordList[i]) == allSave.end()) {
                        save.push(item(wordList[i], now.deep + 1));
                        allSave.insert(pair<string, int>(wordList[i], now.deep + 1));
                        //reflex[wordList[i]].push_back(now.str);
                    }
                }
            }
        }

        return 0;

    }

    struct item {
        string str;
        int deep;
        item(string s, int d) : str(s), deep(d) {}
    };

    bool match(string& s1, string& s2) {
        int cnt = 0;
        int len = s1.length();

        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i])
                cnt++;

            if (cnt > 1)
                return false;
        }

        return cnt <= 1;
    }
};