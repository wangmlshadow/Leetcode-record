#include "normal.h"

/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> helper;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            map<int, int>::iterator iter = helper.find(nums[i]);

            if (iter == helper.end())
                helper[nums[i]] = i;
            else {
                if (i - helper[nums[i]] <= k)
                    return true;
                else
                    helper[nums[i]] = i;
            }
        }

        return false;
    }
};

class Solution {   // 用队列试试 时间复杂度因该是kN  还没用hash表快
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;

        int size = nums.size();
        queue<int> q;
        set<int> s;

        for (int i = 0; i < size && i < k; i++) {
            set<int>::iterator iter = s.find(nums[i]);

            if (iter != s.end())
                return true;
            else {
                q.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        for (int i = k; i < size; i++) {
            set<int>::iterator iter = s.find(nums[i]);

            if (iter != s.end())
                return true;
            else {
                s.erase(q.front());
                q.pop();
                q.push(nums[i]);
                s.insert(nums[i]);
            }
        }

        return false;
    }
};
