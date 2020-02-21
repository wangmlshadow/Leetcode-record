#include "normal.h"

/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
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
};