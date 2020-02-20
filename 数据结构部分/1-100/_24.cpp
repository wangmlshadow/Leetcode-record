#include "normal.h"

/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return head;

        ListNode* cur = head;
        ListNode* temp_1 = head->next;
        ListNode* temp_2 = head->next->next;

        cur->next = temp_2;
        temp_1->next = cur;
        head = temp_1;

        ListNode* ahead = cur;
        cur = temp_2;

        while (cur != NULL) {
            if (cur->next == NULL)
                break;

            temp_1 = cur->next;
            temp_2 = cur->next->next;

            ahead->next = temp_1;
            cur->next = temp_2;
            temp_1->next = cur;
            ahead = cur;
            cur = temp_2;
        }

        return head;
    }
};