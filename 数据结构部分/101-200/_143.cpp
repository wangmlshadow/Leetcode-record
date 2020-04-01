#include "normal.h"

/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;

        vector<ListNode*> helper;
        ListNode* cur = head;

        while (cur != NULL) {
            helper.push_back(cur);
            cur = cur->next;
        }

        int left = 0, right = helper.size() - 1;

        while (left <= right) {
            if (left == right) {
                helper[left]->next = NULL;
                break;
            }

            helper[left]->next = helper[right];
            helper[right]->next = helper[left + 1];

            if (left + 1 == right) {
                helper[right]->next = NULL;
                break;
            }

            left++;
            right--;
        }           
    }
};