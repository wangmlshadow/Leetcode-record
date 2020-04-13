#include "normal.h"

/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len_1 = s.length();
        int len_2 = t.length();

        if (len_1 != len_2)
            return false;

        vector<int> posS(len_1, 0);
        vector<int> posT(len_2, 0);
        map<char, int> helper;

        for (int i = 0; i < len_1; i++) {
            if (helper.find(s[i]) == helper.end()) {
                posS[i] = i;
                helper[s[i]] = i;
            }
            else
                posS[i] = helper[s[i]];
        }

        map<char, int> helper_1;

        for (int i = 0; i < len_2; i++) {
            if (helper_1.find(t[i]) == helper_1.end()) {
                posT[i] = i;
                helper_1[t[i]] = i;
            }
            else
                posT[i] = helper_1[t[i]];
        }

        for (int i = 0; i < len_1; i++) {
            if (posS[i] != posT[i])
                return false;
        }

        return true;
    }
};


class Solution {   // 优化
public:
    bool isIsomorphic(string s, string t) {
        int len_1 = s.length();
        int len_2 = t.length();

        if (len_1 != len_2)
            return false;

        map<char, int> helper_1;
        map<char, int> helper_2;

        for (int i = 0; i < len_1; i++) {
            map<char, int>::iterator iter_1 = helper_1.find(s[i]);
            map<char, int>::iterator iter_2 = helper_2.find(t[i]);

            if (iter_1 == helper_1.end()) {
                if (iter_2 != helper_2.end())
                    return false;
                else {
                    helper_1[s[i]] = i;
                    helper_2[t[i]] = i;
                }
            }
            else {
                if (iter_2 == helper_2.end() || helper_1[s[i]] != helper_2[t[i]])
                    return false;
            }
        }

        return true;
    }
};