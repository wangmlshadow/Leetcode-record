/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
*/
// 试试暴力求解
// 结果还挺快
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) {
            return 0;
        }
        int res = numbers[0];// 确保有序数组旋转了 避免没有旋转 反而需要遍历整个数组才能得带答案
        for (int i = numbers.size() - 1; i > 0; --i) {
            if (res >= numbers[i]) {
                res = numbers[i];
            }
            else {
                break;
            }
        }
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了79.79%的用户
*/

// 二分查找，有序列中的二分查找和翻转后的有序查找
// 这里不写了