/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> allNumbers;
        for (auto num : nums) {
            if (allNumbers.count(num) == 0) {
                allNumbers[num] = 1;
            }
            else {
                allNumbers[num] += 1;
            }
        }

        int res;
        for (map<int, int>::iterator it = allNumbers.begin(); it != allNumbers.end(); it++) {
            if (it->second == 1) {
                res = it->first;
                break;
            }
        }

        return res;
    }
};

/*
执行结果：通过 显示详情 添加备注
执行用时：56 ms, 在所有 C++ 提交中击败了15.09%的用户
内存消耗：18.5 MB, 在所有 C++ 提交中击败了5.04%的用户
通过测试用例：32 / 32
*/