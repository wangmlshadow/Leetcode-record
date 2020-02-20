#include "normal.h"

/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;

        ListNode* ahead;
        ListNode* next;
        ListNode* cur = head;
        ListNode* temp_1;
        ListNode* ahead_k;

        int cnt = 1;

        while (cur->next != NULL && cnt < k) {
            cur = cur->next;
            cnt++;
        }

        if (cnt != k) {
            return head;
        }
        else {
            ahead = head;
            head = cur;
            next = cur->next;
            ahead_k = ahead;
                       
            for (int i = 0; i < k; i++) {
                temp_1 = ahead->next;
                ahead->next = next;
                next = ahead;
                ahead = temp_1;
            }
        }

        while (ahead_k->next != NULL) {
            cnt = 1;
            cur = ahead_k->next;

            while (cur->next != NULL && cnt < k) {
                cur = cur->next;
                cnt++;
            }

            if (cnt != k) {
                return head;
            }
            else {
                ahead = ahead_k->next;
                ahead_k->next = cur;
                next = cur->next;
                ahead_k = ahead;

                for (int i = 0; i < k; i++) {
                    temp_1 = ahead->next;
                    ahead->next = next;
                    next = ahead;
                    ahead = temp_1;
                }
            }
        }

        return head;
    }
};