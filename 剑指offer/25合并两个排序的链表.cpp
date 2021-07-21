/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode* head = NULL;
        ListNode* cur = NULL;
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

        while (l1 != NULL) {
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }

        return head;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：24 ms, 在所有 C++ 提交中击败了86.20%的用户
内存消耗：18.6 MB, 在所有 C++ 提交中击败了83.93%的用户
*/