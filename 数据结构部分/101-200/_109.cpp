#include "normal.h"

/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;

        vector<int> nums;

        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return solution(nums, 0, nums.size() - 1);
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