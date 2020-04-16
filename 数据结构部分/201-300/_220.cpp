#include "normal.h"

/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝
对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || t < 0)
            return false;

        int size = nums.size();
        set<long> s;

        if (t == 0) { 
            for (int i = 0; i < size && i < k; i++) {
                if (i == 0)
                    s.insert(nums[i]);
                else {
                    if (s.find(nums[i]) != s.end())
                        return true;
                    
                    s.insert(nums[i]);
                }
            }

            for (int i = k; i < size; i++) {
                if (s.find(nums[i]) != s.end())
                    return true;

                s.insert(nums[i]);
                s.erase(nums[i - k]);
            }

            return false;
        }        

        for (int i = 0; i < size && i < k; i++) {
            if (i == 0)
                s.insert(nums[i]);
            else {
                for (set<long>::iterator iter = s.begin(); iter != s.end(); iter++) {
                    if (abs(*iter - nums[i]) <= t)
                        return true;
                }
                s.insert(nums[i]);
            }
        }

        for (int i = k; i < size; i++) {
            for (set<long>::iterator iter = s.begin(); iter != s.end(); iter++) {
                if (abs(*iter - nums[i]) <= t)
                    return true;
            }
            s.insert(nums[i]);
            s.erase(nums[i - k]);
        }

        return false;
    }
};

class Solution {  // 和上面解法的速度没啥区别
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || t < 0)
            return false;

        int size = nums.size();
        set<long> s;

        for (int i = 0; i < size; i++) {
            long val = nums[i];
            if (s.lower_bound(val - t) != s.end() && (*s.lower_bound(val - t) - val) <= t)
                return true;

            s.insert(val);

            if (s.size() > k)
                s.erase(nums[i - k]);
        }

        return false;
    }
};

