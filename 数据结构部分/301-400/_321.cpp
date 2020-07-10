#include "normal.h"

/*
给定长度分别为?m?和?n?的两个数组，其元素由?0-9?构成，表示两个自然数各位上的数字。现在
从这两个数组中选出 k (k <= m + n)?个数字拼接成一个新的数，要求从同一个数组中取出的数
字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为?k?的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int n = nums1.size(), m = nums2.size();

        for (int s = max(0, k - m); s <= min(k, n); s++) {
            vector<int> temp;
            int i = 0, j = 0;
            vector<int> temp1 = maxKSeq(nums1, s);
            vector<int> temp2 = maxKSeq(nums2, k - s);
            auto iter1 = temp1.begin(), iter2 = temp2.begin();

            while (iter1 != temp1.end() || iter2 != temp2.end())  // 归并
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);

            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }

        return res;
    }

    vector<int> maxKSeq(vector<int>& v, int k) {
        int n = v.size();

        if (n <= k)
            return v;

        vector<int> res;
        int pop = n - k;

        for (int i = 0; i < n; i++) {
            while (!res.empty() && v[i] > res.back() && pop-- > 0)
                res.pop_back();
            res.push_back(v[i]);
        }

        res.resize(k);
        return res;
    }
};