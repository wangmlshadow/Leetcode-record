#include "normal.h"

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 // 超出内存限制
 class Solution {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head = new ListNode(0);
         int temp = l1->val + l2->val;
         bool more = false;

         if (temp > 9) {
             head->val = temp % 10;
             more = true;
             l1 = l1->next;
             l2 = l2->next;
         }
         else {
             head->val = temp;
             more = false;
             l1 = l1->next;
             l2 = l2->next;
         }

         ListNode* last = head;

         while (l1 != NULL && l2 != NULL) {
             ListNode* now = new ListNode(0);
             if (more)
                 temp = l1->val + l2->val + 1;
             else
                 temp = l1->val + l2->val;

             if (temp > 9) {
                 now->val = temp % 10;
                 more = true;
                 l1 = l1->next;
                 l2 = l2->next;
             }
             else {
                 now->val = temp;
                 more = false;
                 l1 = l1->next;
                 l2 = l2->next;
             }

             last->next = now;
             last = now;
         }

         if (l1 == NULL && l2 == NULL && more) {
             ListNode* now = new ListNode(1);
             last->next = now;
             last = now;
         }

         while (l1 != NULL) {
             if (more) {
                 ListNode* now = new ListNode(l1->val + 1);
                 more = false;
             }
             ListNode* now = new ListNode(l1->val);
             last->next = now;
             last = now;
         }

         while (l2 != NULL) {
             if (more) {
                 ListNode* now = new ListNode(l2->val + 1);
                 more = false;
             }
             ListNode* now = new ListNode(l2->val);
             last->next = now;
             last = now;
         }

         return head;
     }
 };


 class Solution {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int temp = l1->val + l2->val;
         ListNode* head = new ListNode(temp%10);
         bool more;
         if (temp > 9)
             more = true;
         else
             more = false;
         ListNode* last = head;
         l1 = l1->next;
         l2 = l2->next;

         while (l1 != NULL || l2 != NULL) {
             if (l1 != NULL && l2 != NULL) {
                 temp = l1->val + l2->val;
                 l1 = l1->next;
                 l2 = l2->next;
             }      
             else if (l1 != NULL && l2 == NULL) {
                 temp = l1->val;
                 l1 = l1->next;
             }                
             else {
                 temp = l2->val;
                 l2 = l2->next;
             };
             if (more)
                 temp++;
             ListNode* now = new ListNode(temp % 10);
             last->next = now;
             last = now;
             if (temp > 9)
                 more = true;
             else
                 more = false;
         }
         
         if (more) {
             ListNode* now = new ListNode(1);
             last->next = now;
             last = now;
         }

         return head;
     }
 };