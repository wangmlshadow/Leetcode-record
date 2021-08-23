/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
*/

// 双指针加map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }

        int res = 0;
        int left = 0, right = -1;// left-right 标识子串
        map<char, bool> has;

        for (int i = 0; i < s.length(); i++) {
            if (has.count(s[i]) == 0 || has[s[i]] == false) {// 子串中不包含此字符
                has[s[i]] = true;
                ++right;
            }
            else {
                res = max(res, right - left + 1);
                while (left <= right && s[left] != s[i]) {
                    has[s[left]] = false;
                    ++left;
                }
                ++left;
                ++right;
            }
        }

        res = max(res, right - left + 1);
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 C++ 提交中击败了45.43%的用户
内存消耗：8.4 MB, 在所有 C++ 提交中击败了34.20%的用户
*/