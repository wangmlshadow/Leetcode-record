#include "normal.h"

/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;

        int len = 1;
        ListNode* cur = head;

        while (cur->next != NULL) {
            len++;
            cur = cur->next;
        }

        ListNode* end = cur;

        if (k % len == 0)
            return head;

        k = len - k % len;

        cur = head;

        for (int i = 1; i < k; i++)
            cur = cur->next;

        ListNode* Head = cur->next;
        cur->next = NULL;
        end->next = head;

        return Head;
    }
};