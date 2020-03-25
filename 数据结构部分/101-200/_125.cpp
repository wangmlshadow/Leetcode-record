#include "normal.h"

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;

            while (right > left && !isalnum(s[right]))
                right--;

            if (left < right) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                    continue;
                }

                if (isdigit(s[left])) {
                    if (s[left] == s[right]) {
                        left++;
                        right--;
                        continue;
                    }
                    else
                        return false;
                }
                else {
                    if ((char)(toupper(s[left])) == (char)(toupper(s[right]))) {
                        left++;
                        right--;
                        continue;
                    }
                    else
                        return false;
                }
            }
        }

        return true;
    }
};