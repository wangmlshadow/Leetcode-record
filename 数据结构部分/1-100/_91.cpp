#include "normal.h"

/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
*/

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0 || s[0] == '0')
            return 0;
        
        for (int i = 1; i < len; i++) {
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] - '0' > 2))
                return 0;
        }

        return solution(s, 0, len);
    }

private:
    int solution(string& s, int pos, int len) {
        if (pos >= len - 1)
            return 1;
        else if (pos == len - 2) {
            int cur = s[pos] - '0';
            int next = s[pos + 1] - '0';
            
            if (cur > 2)
                return 1;
            else if (cur == 2) {
                if (next > 6 || next == 0)
                    return 1;
                else
                    return 2;
            }
            else {
                if (next == 0)
                    return 1;
                else
                    return 2;
            }

        }
        else {
            int cur = s[pos] - '0';
            int next = s[pos + 1] - '0';
            int next_next = s[pos + 2] - '0';

            if (next_next == 0)
                return solution(s, pos + 3, len);
            else {
                if (cur > 2)
                    return solution(s, pos + 1, len);
                else if (cur == 2) {
                    if (next > 6)
                        return solution(s, pos + 1, len);
                    else if (next == 0)
                        return solution(s, pos + 2, len);
                    else
                        return solution(s, pos + 1, len) + solution(s, pos + 2, len);
                }
                else {
                    if (next == 0)
                        return solution(s, pos + 2, len);
                    else
                        return solution(s, pos + 1, len) + solution(s, pos + 2, len);
                }
            }
        }      
    }
};