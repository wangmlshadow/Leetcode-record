#include "normal.h"

/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = head;
        ListNode* right;
        ListNode* cur = head;

        while (cur != NULL) {
            if (cur->val >= x)
                break;
            left = cur;
            cur = cur->next;
        }

        if (cur == NULL)
            return head;

        ListNode* ahead = cur;
        right = cur->next;

        while (right != NULL) {
            if (right->val >= x) {
                ahead = right;
                right = right->next;
            }
            else {
                ahead->next = right->next;

                if (head == cur) {
                    right->next = head;
                    head = right;
                    left = head;
                }
                else {
                    right->next = left->next;
                    left->next = right;
                    left = right;
                }

                right = ahead->next;
            }
        }        
       
        return head;
    }
};