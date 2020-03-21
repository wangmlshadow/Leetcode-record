#include "normal.h"

/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return NULL;

        return solution(nums, 0, size - 1);
    }

    TreeNode* solution(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        if (mid <= start)
            root->left = NULL;
        else
            root->left = solution(nums, start, mid - 1);

        if (mid >= end)
            root->right = NULL;
        else
            root->right = solution(nums, mid + 1, end);

        return root;
    }
};