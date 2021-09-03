/*
输入两个链表，找出它们的第一个公共节点。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> allNodes;
        while (headA != NULL && headB != NULL) {
            if (allNodes.count(headA) == 0) {
                allNodes.insert(headA);
            }
            else {
                return headA;
            }
            headA = headA->next;

            if (allNodes.count(headB) == 0) {
                allNodes.insert(headB);
            }
            else {
                return headB;
            }
            headB = headB->next;
        }

        while (headA != NULL) {
            if (allNodes.count(headA) == 0) {
                allNodes.insert(headA);
            }
            else {
                return headA;
            }
            headA = headA->next;
        }

        while (headB != NULL) {
            if (allNodes.count(headB) == 0) {
                allNodes.insert(headB);
            }
            else {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：80 ms, 在所有 C++ 提交中击败了5.71%的用户
内存消耗：20.7 MB, 在所有 C++ 提交中击败了5.01%的用户
通过测试用例：45 / 45
*/