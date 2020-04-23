#include "normal.h"

/*
将非负整数转换为其对应的英文表示。可以保证给定输入小于 231 - 1 。

输入: 1 234 567 891
输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-english-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 2^31-1 = 214748364
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string res;
        int cnt = 0;

        while (num != 0) {
            string cur;
            if (num % 1000 != 0) {
                cur = getThreeNum(to_string(num % 1000));
            }

            if (cnt == 0)
                res = cur;
            else if (cnt == 1) {
                if (!cur.empty()) {
                    if (res.empty())
                        res = cur + " " + "Thousand";
                    else
                        res = cur + " " + "Thousand" + " " + res;
                }                
            }
            else if (cnt == 2) {
                if (!cur.empty()) {
                    if (res.empty())
                        res = cur + " " + "Million";
                    else
                        res = cur + " " + "Million" + " " + res;
                }
            }
            else {
                if (!cur.empty()) {
                    if (res.empty())
                        res = cur + " " + "Billion";
                    else
                        res = cur + " " + "Billion" + " " + res;
                }
            }

            cnt++;
            num /= 1000;
        }
                
        return res;
    }

    string getThreeNum(string s) {
        vector<string> f1 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
        vector<string> f2 = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        vector<string> f3 = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        string res;

        if (s.length() == 3) {
            int n1 = s[0] - '0';
            int n2 = s[1] - '0';
            int n3 = s[2] - '0';

            if (n1 != 0)
                res = f1[n1] + " " + "Hundred";

            if (n2 != 0) {
                if (n2 == 1) {
                    if (res.empty())
                        res = f2[n3];
                    else
                        res = res + " " + f2[n3];
                }
                else {
                    if (res.empty())
                        res = f3[n2];
                    else
                        res = res + " " + f3[n2];

                    if (n3 != 0)
                        res = res + " " + f1[n3];
                }
            }
            else {
                if (res.empty())
                    res = f1[n3];
                else {
                    if (n3 != 0)
                        res = res + " " + f1[n3];
                }                   
            }
        }
        else if (s.length() == 2) {
            int n2 = s[0] - '0';
            int n3 = s[1] - '0';

            if (n2 != 0) {
                if (n2 == 1) {
                    res = f2[n3];
                }
                else {
                    res = f3[n2];

                    if (n3 != 0)
                        res = res + " " + f1[n3];
                }
            }
            else {
                res = f1[n3];
            }
        }
        else {
            int n3 = s[0] - '0';
            res = f1[n3];
        }

        return res;
    }
};