#include "normal.h"

/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {        
        if (head == NULL)
            return NULL;

        ListNode* last = head;
        ListNode* cur = head;
        int val;
        bool sign = false;   // 头节点可以被确定

        while (cur != NULL) {
            val = cur->val;
            int cnt = 1;

            while (cur->next != NULL && cur->next->val == val) {
                cur = cur->next;
                cnt++;
            }

            if (cnt == 1) {
                if (sign) {
                    last->next = cur;
                    last = cur;
                }
                else {
                    head = cur;
                    last = cur;
                }

                sign = true;
            }
            else {
                if (sign) {
                    last->next = cur->next;
                }
                else {
                    head = cur->next;
                    last = cur->next;
                }
            }
            
            cur = cur->next;
        }
               
        return head;
    }
};