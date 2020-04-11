#include "normal.h"

/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        vector<string> helper;

        for (int i = 0; i < size; i++)
            helper.push_back(to_string(nums[i]));

        mySort(helper);
        string res;

        for (int i = 0; i < size; i++)
            res += helper[i];

        if (res.length() > 1 && res[0] == '0')
            return "0";

        return res;
    }

    void mySort(vector<string>& helper) {
        int size = helper.size();

        for (int i = 1; i < size; i++) {
            int cur = i;

            for (int j = i - 1; j >= 0; j--) {
                if (cmp(helper[i], helper[j])) {
                    cur = j;
                }
                else {                    
                    break;
                }
            }

            string str = helper[i];

            for (int j = i; j > cur; j--)
                helper[j] = helper[j - 1];

            helper[cur] = str;
        }
    }

    bool cmp(string s1, string s2) {  // s1 > s2此处自定义的 并不是数学上的大于 而是在最终结果上 s1排在s2前面
        int len_1 = s1.length();
        int len_2 = s2.length();

        if (len_2 == 0)
            return false;
        
        int i = 0;
        while (i < len_1 && i < len_2) {
            if (s1[i] != s2[i]) {
                return int(s1[i] - s2[i]) > 0;
            }
            i++;
        }

        if (i == len_1 && i == len_2)
            return false;

        if (i == len_1 && i < len_2) {
            return cmp(s1, s2.substr(i));
        }

        if (i == len_2 && i < len_1) {
            return !cmp(s2, s1.substr(i));
        }
        
        return false;
    }
};

/*
"98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322281216213206020001921763154815181495141713801147114310901048"
"98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048"
*/-