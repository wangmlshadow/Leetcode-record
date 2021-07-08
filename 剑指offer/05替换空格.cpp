/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/

class Solution {
public:
    string replaceSpace(string s) {
        // C++的replace没有python那个全部替换的功能
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                res += "%20";
            }
            else {
                res += string(1, s[i]);
            }
        }
        return res;
    }
};

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了72.66%的用户
*/