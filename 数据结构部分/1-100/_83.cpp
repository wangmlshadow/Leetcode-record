#include "normal.h"

/*

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode* cur = head->next;
        ListNode* last = head;

        while (cur != NULL) {
            if (last->val == cur->val) {
                last->next = cur->next;
                cur = cur->next;
            }
            else {
                last = cur;
                cur = cur->next;
            }                                      
        }

        return head;
    }
};