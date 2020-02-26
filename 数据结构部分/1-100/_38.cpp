#include "normal.h"

/*
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        string next;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < cur.length(); j++) {
                int cnt = 1;
                char ch = cur[j];

                while (j + 1 < cur.length() && cur[j + 1] == cur[j]) {
                    j++;
                    cnt++;
                }
                
                next.append(1, (char)('0' + cnt));
                next.append(1, ch);
            }
            cur = next;
            next.clear();
        }

        return cur;
    }
};