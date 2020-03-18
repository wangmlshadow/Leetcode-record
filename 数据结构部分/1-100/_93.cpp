#include "normal.h"

/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();

        if (len < 4 || len > 12)
            return result;

        vector<string> res(4);
        solution(s, 0, res, 0);
        return result;
    }

private:
    vector<string> result;

    void solution(string& s, int pos, vector<string> res, int cnt) {
        if (pos >= s.length() || cnt > 3)
            return;

        string temp = res[cnt];
        temp.push_back(s[pos]);

        if (temp.length() == 1 && temp[0] == '0') {   // 0单独做一位
            vector<string> temp_1 = res;
            temp_1[cnt] = temp;

            if (pos == s.length() - 1 && cnt == 3) {
                string one = temp_1[0];

                for (int i = 1; i < 4; i++) {
                    one.push_back('.');
                    one += temp_1[i];
                }

                result.push_back(one);
                return;
            }

            solution(s, pos + 1, temp_1, cnt + 1);
            return;
        }

        if (temp.length() < 3) {
            vector<string> temp_1 = res;
            temp_1[cnt] = temp;

            if (pos == s.length() - 1 && cnt == 3) {
                string one = temp_1[0];

                for (int i = 1; i < 4; i++) {
                    one.push_back('.');
                    one += temp_1[i];                   
                }

                result.push_back(one);
                return;
            }

            solution(s, pos + 1, temp_1, cnt);
            solution(s, pos + 1, temp_1, cnt + 1);
        }
        else {
            int num = 0;

            for (int i = 0; i < 3; i++)
                num = num * 10 + temp[i] - '0';
            
            if (num <= 255) {     // 不需要管大于255，因为temp.length() < 3中包含了这种情况，避免重复
                vector<string> temp_1 = res;
                temp_1[cnt] = temp;

                if (pos == s.length() - 1 && cnt == 3) {
                    string one = temp_1[0];

                    for (int i = 1; i < 4; i++) {
                        one.push_back('.');
                        one += temp_1[i];
                    }

                    result.push_back(one);
                    return;
                }

                solution(s, pos + 1, temp_1, cnt + 1);
            }
        }       
    }
};