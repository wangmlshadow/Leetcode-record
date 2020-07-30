#include "normal.h"

/*
数组

给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> another;   // 未在arr2中出现的
        map<int, int> m;       // 出现在arr2中的

        set<int> s;
        for (auto n : arr2)
            s.insert(n);

        for (auto n : arr1) {
            if (s.find(n) != s.end())
                m[n]++;
            else
                another.push_back(n);
        }

        vector<int> res;

        for (auto n : arr2) {
            for (int i = 0; i < m[n]; i++)
                res.push_back(n);
        }

        sort(another.begin(), another.end());
        res.insert(res.end(), another.begin(), another.end());

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：16 ms, 在所有 C++ 提交中击败了10.27%的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了9.52%的用户
*/