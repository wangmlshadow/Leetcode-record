#include "normal.h"

/*
数组

给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

思路：补充0之后arr右边元素会被挤出来，找到最后结果中位于最右端的元素 然后依次替换即可
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int cnt = 0, end = 0;

        for ( ; end < size; end++) {
            cnt++;
            if (arr[end] == 0)
                cnt++;

            if (cnt >= size)
                break;
        }

        if (end == size - 1)
            return;

        int right = size - 1;

        if (cnt > size) {
            arr[right--] = arr[end--];
        }

        for (; end >= 0; end--) {
            arr[right--] = arr[end];

            if (arr[end] == 0)
                arr[right--] = arr[end];           
        }

        return;
    }
};

/*
执行结果：通过 显示详情
执行用时：20 ms, 在所有 C++ 提交中击败了45.10%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了12.50%的用户
*/