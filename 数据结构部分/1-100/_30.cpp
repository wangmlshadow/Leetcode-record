#include "normal.h"

/*
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 超时
class Solution {  // 注意给出的单词长度相同
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.size() == 0 || words[0].empty() || s.length() < words.size() * words[0].length())
            return result;

        vector<int> temp;
        int pos;
        int left, right;
        

        for (int j = 0; j < s.length(); ) {
            string cur = s.substr(j);
            pos = strStr(cur, words[0]);   // 找出第一个单词第一次出现的位置

            if (pos == -1)
                return result;

            // 此处传入的不是cur, 因此要pos + j
            bool suc = wordsStr(s, words, pos + j, left, right);  // 判断若该单词自此位置时，能否匹配成功，若成功返回匹配完全后首位置，若不成功返回-1

            if (!suc)
                j = pos + 1 + j;
            else {
                result.push_back(left);
                j = right + 1;
            }
        }
               
        return result;
    }

    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;

        int cur_1 = 0, cur_2 = 0;

        while (cur_1 < haystack.length()) {
            if (haystack[cur_1] == needle[cur_2]) {
                cur_1++;
                cur_2++;

                if (cur_2 == needle.length())
                    return cur_1 - cur_2;
            }
            else {
                cur_1 = cur_1 - cur_2 + 1;
                cur_2 = 0;

                if (cur_1 > haystack.length() - needle.length())
                    return -1;
            }
        }
        return -1;
    }

    bool wordsStr(string& s, vector<string>& words, int pos, int &left, int &right) {
        vector<bool> sign(words.size(), false);
        sign[0] = true;
        int len = words[0].length();

        // 沿此位置分别向前、向后搜索
        int begin= pos;
        int end = pos + len - 1;
        bool suc = false;
        string temp_1, temp_2;

        int h = begin, t = end;  // 记录需要返回的位置

        while (begin >= 0 || end < s.length()) {
            if (begin - len >= 0) {   // 先前一个
                temp_1 = s.substr(begin - len, len);

                for (int i = 1; i < words.size(); i++) {
                    if (temp_1 == words[i]) {
                        if (!sign[i]) {
                            sign[i] = true;
                            begin = begin - len;
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }

                if (begin != h)
                    h = begin;
                else
                    begin = -1;
            }

            if (end + len < s.length()) {  // 向后一个
                temp_2 = s.substr(end + 1, len);

                for (int i = 1; i < words.size(); i++) {
                    if (temp_2 == words[i]) {
                        if (!sign[i]) {
                            sign[i] = true;
                            end = end + len;
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }

                if (end != t)
                    t = end;
                else
                    end = s.length();
            }
        }

        // 如果匹配成功则sign全是true

        for (int j = 0; j < words.size(); j++)
            if (!sign[j])
                return false;

        left = h;
        right = t;

        return true;
    }
};


class Solution {  // 注意给出的单词长度相同
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.size() == 0 || words[0].empty() || s.length() < words.size() * words[0].length())
            return result;

        vector<int> temp;
        int pos;
        int left, right;
        

        for (int j = 0; j < s.length(); ) {
            string cur = s.substr(j);
            pos = strStr(cur, words[0]);   // 找出第一个单词第一次出现的位置

            if (pos == -1)
                return result;

            // 此处传入的不是cur, 因此要pos + j
            bool suc = wordsStr(s, words, pos + j, left, right);  // 判断若该单词自此位置时，能否匹配成功，若成功返回匹配完全后首位置，若不成功返回-1

            if (!suc)
                j = pos + 1 + j;
            else {
                result.push_back(left);
                j = right + 1;
            }
        }
               
        return result;
    }

    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;

        int cur_1 = 0, cur_2 = 0;

        while (cur_1 < haystack.length()) {
            if (haystack[cur_1] == needle[cur_2]) {
                cur_1++;
                cur_2++;

                if (cur_2 == needle.length())
                    return cur_1 - cur_2;
            }
            else {
                cur_1 = cur_1 - cur_2 + 1;
                cur_2 = 0;

                if (cur_1 > haystack.length() - needle.length())
                    return -1;
            }
        }
        return -1;
    }

    bool wordsStr(string& s, vector<string>& words, int pos, int &left, int &right) {
        vector<bool> sign(words.size(), false);
        sign[0] = true;
        int len = words[0].length();

        // 沿此位置分别向前、向后搜索
        int begin= pos;
        int end = pos + len - 1;
        bool suc = false;
        string temp_1, temp_2;

        int h = begin, t = end;  // 记录需要返回的位置

        while (begin >= 0 || end < s.length()) {
            if (begin - len >= 0) {   // 先前一个
                temp_1 = s.substr(begin - len, len);

                for (int i = 1; i < words.size(); i++) {
                    if (temp_1 == words[i]) {
                        if (!sign[i]) {
                            sign[i] = true;
                            begin = begin - len;
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }

                if (begin != h)
                    h = begin;
                else
                    begin = -1;
            }

            if (end + len < s.length()) {  // 向后一个
                temp_2 = s.substr(end + 1, len);

                for (int i = 1; i < words.size(); i++) {
                    if (temp_2 == words[i]) {
                        if (!sign[i]) {
                            sign[i] = true;
                            end = end + len;
                            break;
                        }
                        else {
                            continue;
                        }
                    }
                }

                if (end != t)
                    t = end;
                else
                    end = s.length();
            }
        }

        // 如果匹配成功则sign全是true

        for (int j = 0; j < words.size(); j++)
            if (!sign[j])
                return false;

        left = h;
        right = t;

        return true;
    }
};



class Solution {   //  还是太慢了
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (s.length() == 0 || words.size() == 0 || words[0].length() == 0)
            return result;

        int len = words[0].length();
        int cnt = words.size();

        if (s.length() < len * cnt)
            return result;

        for (int i = 0; i <= s.length() - len * cnt; i++) {     // 从前往后尝试
            string cur = s.substr(i, len * cnt);

            if (isMatch(cur, words, len, cnt)) {
                result.push_back(i);
            }              
        }

        return result;
    }

    bool isMatch(string& cur, vector<string>& words, int len, int cnt) {
        vector<bool> sign(words.size(), false);

        for (int i = 0; i < cnt; i++) {
            string sub = cur.substr(i * len, len);
            int j;
            for (j = 0; j < cnt; j++) {
                if (words[j] == sub) {
                    if (sign[j] == false) {
                        sign[j] = true;
                        break;
                    }
                    else
                        continue;
                }
            }

            if (j == cnt)
                return false;
        }

        for (int i = 0; i < cnt; i++) {
            if (sign[i] == false)
                return false;
        }

        return true;
    }
};

// 通过与题解中的一些答案比较，发现是测试isMatch（）太慢了，题解中有一个提到通过给vector<string> 排序再比较的方法
// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/jian-dan-de-shu-zu-pai-xu-zai-bi-jiao-by-socolikat/
// 参考上述方法再写了一遍


class Solution {    // 通过了，但看执行用时以及内存情况，还是比较慢
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (s.length() == 0 || words.size() == 0 || words[0].length() == 0)
            return result;

        int len = words[0].length();
        int cnt = words.size();

        if (s.length() < len * cnt)
            return result;

        sort(words.begin(), words.end());

        for (int i = 0; i <= s.length() - len * cnt; i++) {     // 从前往后尝试
            string cur = s.substr(i, len * cnt);

            if (isMatch(cur, words, len, cnt)) {
                result.push_back(i);
            }
        }

        return result;
    }

    bool isMatch(string& cur, vector<string>& words, int len, int cnt) {
        vector<string> cur_words;

        for (int i = 0; i < cnt; i++) {
            cur_words.push_back(cur.substr(i * len, len));
        }

        sort(cur_words.begin(), cur_words.end());

        if (words == cur_words)
            return true;
        else
            return false;
    }
};