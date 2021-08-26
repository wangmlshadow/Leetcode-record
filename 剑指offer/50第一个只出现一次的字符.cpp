/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
*/

class Solution {
public:
    char firstUniqChar(string s) {
        if (s.length() == 0) return ' ';

        map<char, pair<int, int>> all;  // 记录字符出现位置和次数

        for (int i = 0; i < s.length(); ++i) {
            if (all.count(s[i]) == 0) {
                all[s[i]] = pair<int, int>(i, 1);
            }
            else {
                all[s[i]].second += 1;
            }
        }

        char res = ' ';
        int pos = s.length();

        for (map<char, pair<int, int>>::iterator it = all.begin(); it != all.end(); ++it) {
            if ((it->second).second == 1 && pos > (it->second).first) {
                res = it->first;
                pos = (it->second).first;
            }
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：60 ms, 在所有 C++ 提交中击败了21.46%的用户
内存消耗：10.7 MB, 在所有 C++ 提交中击败了5.18%的用户
*/