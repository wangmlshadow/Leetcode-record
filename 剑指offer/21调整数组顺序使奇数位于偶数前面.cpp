class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> res(nums);
        int left = 0, right = res.size() - 1;
        while (left < right) {
            if (res[left] % 2 == 0) { // 偶数
                swap(res[left], res[right]);
                --right;
            }
            else {
                ++left;
            }
        }
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 C++ 提交中击败了99.01%的用户
内存消耗：17.7 MB, 在所有 C++ 提交中击败了24.97%的用户
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //vector<int> res(nums);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 == 0) { // 偶数
                swap(nums[left], nums[right]);
                --right;
            }
            else {
                ++left;
            }
        }
        return nums;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：24 ms, 在所有 C++ 提交中击败了53.57%的用户
内存消耗：17.5 MB, 在所有 C++ 提交中击败了96.47%的用户
*/