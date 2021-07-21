/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始
计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。
这个链表的倒数第 3 个节点是值为 4 的节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* first = head;
        while (k > 1 && first != NULL) {
            first = first->next;
            --k;
        }
        if (first == NULL) {
            return NULL;
        }
        ListNode* second = head;
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        return second;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了29.58%的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了58.77%的用户
*/