#include "normal.h"

/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 暴力法 最后一个案例超时
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;

            for (int j = i + 1; j < nums.size(); j++)
                if (nums[j] < nums[i])
                    cnt++;

            res.push_back(cnt);
        }

        return res;
    }
};

class Solution {   // 还是超时
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};

        multiset<int> s;
        s.insert(*nums.rbegin());
        vector<int> res(1, 0);
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            s.insert(nums[i]);
            multiset<int>::iterator iter = s.find(nums[i]);
            int cnt = 0;

            for (multiset<int>::iterator cur = s.begin(); cur != iter; cur++)
                cnt++;

            res.push_back(cnt);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {  // 还是超时
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};

        multiset<int> s;
        s.insert(*nums.rbegin());
        vector<int> res(1, 0);

        for (int i = nums.size() - 2; i >= 0; i--) {
            s.insert(nums[i]);
            int cnt = 0;

            for (multiset<int>::iterator cur = s.begin(); *cur != nums[i]; cur++)
                cnt++;

            res.push_back(cnt);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {   // 倒序 二分插入 通过
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<int> res(1, 0);
        vector<int> sorted(nums);
        reverse(sorted.begin(), sorted.end());

        for (int i = 1; i < sorted.size(); i++) {
            res.push_back(getRes(sorted, i));
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int getRes(vector<int>& sorted, int end) {
        int left = 0, right = end - 1;
        int res = 0;
        int val = sorted[end];

        while (left <= right) {
            int mid = (left + right) / 2;

            if (sorted[mid] > val)
                right = mid - 1;
            else
                left = mid + 1;
        }

        int temp = left - 1;
        int cnt = 0;

        while (temp >= 0 && sorted[temp] == val) {
            temp--;
            cnt++;
        }

        res = left - cnt;

        for (int i = end - 1; i >= left; i--) {
            sorted[i + 1] = sorted[i];
        }

        if (sorted[left] != val) {
            sorted[left] = val;
        }

        return res;
    }
};

