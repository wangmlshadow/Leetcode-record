#include "normal.h"

/*
你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他
一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位数字猜对了但是位置
不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。

请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。

请注意秘密数字和朋友的猜测数都可能含有重复数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulls-and-cows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int len = secret.length();

        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i])
                A++;
        }

        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());

        int i = 0, j = 0;

        while (i < len && j < len) {
            if (secret[i] == guess[j]) {
                i++;
                j++;
                B++;
            }
            else if (secret[i] > guess[j]) {
                j++;
            }
            else {
                i++;
            }
        }

        B -= A;

        string res;
        res += to_string(A);
        res += "A";
        res += to_string(B);
        res += "B";
        return res;
    }
};

