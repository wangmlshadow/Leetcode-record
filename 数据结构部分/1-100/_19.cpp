#include "normal.h"

/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> result;
        ListNode* cur = head;

        while (cur != NULL) {
            result.push_back(cur);
            cur = cur->next;
        }

        if (n == result.size()) {
            //delete result[0];

            if (result[0]->next != NULL)
                return result[1];
            else
                return NULL;
        }

        cur = result[result.size() - n];
        result[result.size() - n - 1]->next = cur->next;

        //delete cur;

        return result[0];
    }
};

// 快慢指针，不需要额外的储存空间