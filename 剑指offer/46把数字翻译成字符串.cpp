/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字
可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/

// 类似于上楼 每一次可以走一步或者走两步 有多少种走法
// 不过需要根据题目做处理
// 0-25才可以翻译
class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);

        // 特殊情况处理
        if (numStr.length() <= 0) {
            return 0;
        }
        if (numStr.length() == 1) {
            return 1;
        }
        if (numStr.length() == 2) {
            if (num <= 25) {
                return 2;
            }
            return 1;
        }

        int cnt_1 = 1, cnt_2, cnt_3;
        if (numStr[0] == '1' || (numStr[0] == '2' && numStr[1] < '6')) {
            cnt_2 = 2;
        }
        else {
            cnt_2 = 1;
        }

        for (int i = 2; i < numStr.size(); i++) {
            if (numStr[i - 1] == '1' || (numStr[i - 1] == '2' && numStr[i] < '6')) {
                cnt_3 = cnt_1 + cnt_2;
            }
            else {
                cnt_3 = cnt_2;
            }
            cnt_1 = cnt_2;
            cnt_2 = cnt_3;
        }

        return cnt_3;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了26.93%的用户
*/