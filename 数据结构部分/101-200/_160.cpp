#include "normal.h"

/*
编写一个程序，找到两个单链表相交的起始节点。

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 用set的话空间复杂度为O(n)
        //set<ListNode*> setA;

        // 双指针法
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != NULL && curB != NULL) {   // 若A B一样长 如果有交点第一遍遍历就可以找出 如果不一样长 如果有交点 第二次遍历可以找出 如果没有交点curA curB会在第二次遍历时出现同为NULL
            if (curA == curB)
                return curA;
            
            curA = curA->next;
            curB = curB->next;

            if (curA == NULL && curB == NULL)
                return NULL;

            if (curA == NULL)
                curA = headB;

            if (curB == NULL)
                curB = headA;
        }

        return NULL;
    }
};