#include "normal.h"

/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == "" || endWord == "" || wordList.empty())
            return {};

        queue<item> save;
        unordered_map<string, int> allSave;
        unordered_map<string, vector<string>> reflex;
        vector<vector<string>> allPath;
        bool findEnd = false;
        save.push(item(beginWord, 1));
        allSave.insert(pair<string, int>(beginWord, 1));
        int size = wordList.size();

        while (!save.empty()) {
            item now = save.front();
            save.pop();

            if (now.str == endWord) {
                findEnd = true;
                break;
            }

            for (int i = 0; i < size; i++) {
                if (match(now.str, wordList[i])) {
                    if (allSave.find(wordList[i]) == allSave.end()) {
                        save.push(item(wordList[i], now.deep + 1));
                        allSave.insert(pair<string, int>(wordList[i], now.deep + 1));
                        reflex[wordList[i]].push_back(now.str);
                    }
                    else {
                        if (allSave[wordList[i]] <= now.deep)
                            continue;
                        else
                            reflex[wordList[i]].push_back(now.str);
                    }                             
                }
            }
        }

        if (!findEnd)
            return {};

        dfs(beginWord, endWord, reflex, {}, allPath);

        return allPath;
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

    void dfs(string& beginWord, string toTrace, unordered_map<string, vector<string>>& reflex, vector<string> path, vector<vector<string>>& allPath) {
        if (toTrace == beginWord) {
            path.push_back(toTrace);
            reverse(path.begin(), path.end());
            allPath.push_back(path);
            return;
        }

        path.push_back(toTrace);

        for (auto& i : reflex[toTrace])    // end->begin
            dfs(beginWord, i, reflex, path, allPath);
    }
};