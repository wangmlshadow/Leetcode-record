#include "normal.h"

/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        ListNode* head;
        ListNode* cur;

        if (l1->val < l2->val) {
            head = l1;
            cur = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            cur = l2;
            l2 = l2->next;
        }


        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        if (l1 != NULL)
            cur->next = l1;

        if (l2 != NULL)
            cur->next = l2;

        return head;
    }
};