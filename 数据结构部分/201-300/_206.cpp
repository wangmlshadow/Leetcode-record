#include "normal.h"

/*
反转一个单链表。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {   // 采用递归的方式反转
public:
    ListNode* reverseList(ListNode* head) {
        return reverseNode(head, NULL);
    }

    ListNode* reverseNode(ListNode* cur, ListNode* next) {
        if (cur == NULL)
            return next;

        ListNode* temp = cur->next;
        cur->next = next;

        return reverseNode(temp, cur);
    }
};