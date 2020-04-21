#include "normal.h"

/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其
中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {  // 不能忘记0
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt = nums.size();
        long long all = 1;
        int zeros = 0;
        int posZero = 0;

        for (int i = 0; i < cnt; i++) {
            if (nums[i] != 0) {
                all *= nums[i];
            }
            else {
                posZero = i;
                zeros++;

                if (zeros == 2)
                    break;
            }
        }

        vector<int> res(cnt, 0);
            
        if (zeros == 2)
            return res;

        if (zeros == 1) {
            
            res[posZero] = all;
            return res;
        }
     
        for (int i = 0; i < cnt; i++)
            res[i] = all / nums[i];

        return res;
    }
};