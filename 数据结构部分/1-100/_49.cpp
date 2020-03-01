#include "normal.h"

/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> sign;

        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            int j;

            for (j = 0; j < sign.size(); j++) {
                if (cur == sign[j])
                    break;
            }

            if (j < sign.size()) {
                result[j].push_back(strs[i]);
            }
            else {
                sign.push_back(cur);
                result.push_back({ strs[i]});
            }           
        }

        return result;
    }
};