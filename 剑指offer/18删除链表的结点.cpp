/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        if (head->val == val) {
            return head->next;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了96.00%的用户
内存消耗：9.1 MB, 在所有 C++ 提交中击败了33.02%的用户
*/