#include "normal.h"

/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只
可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win;
        int cnt = nums.size();
        vector<int> res;

        if (cnt == 0)
            return res;

        if (k > cnt)
            return res;

        if (k == cnt) {
            int maxVal = nums[0];

            for (int i = 1; i < cnt; i++)
                if (maxVal < nums[i])
                    maxVal = nums[i];

            res.push_back(maxVal);
            return res;
        }

        for (int i = 0; i < k; i++)
            win.insert(nums[i]);

        res.push_back(*win.rbegin());

        for (int i = k; i < cnt; i++) {
            //win.erase(nums[i - k]);   // 删除了所有重复元素
            multiset<int>::iterator iter = win.find(nums[i - k]);
            win.erase(iter);
            win.insert(nums[i]);
            res.push_back(*win.rbegin());
        }

        return res;
    }
};