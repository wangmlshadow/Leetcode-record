#include "normal.h"

/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int> topK; // set不能元素不能重复
        int size = nums.size();
        multiset<int> topK;

        for (int i = 0; i < k; i++) {
            topK.insert(nums[i]);
        }

        for (int i = k; i < size; i++) {
            if (*topK.begin() < nums[i]) {
                topK.erase(topK.begin());
                topK.insert(nums[i]);
            }
        }

        return *topK.begin();
    }
};