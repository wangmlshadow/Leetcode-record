/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
*/

class Solution {
public:
    vector<int> printNumbers(int n) {
        int cnt = (int)pow(10, n) - 1;
        vector<int> res(cnt, 0);
        for (int i = 1; i <= cnt; ++i) {
            res[i - 1] = i; 
        }
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了97.06%的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了92.64%的用户
*/