/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(l1 && l2){
            p->val = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
           if(l1 && l2){
            ListNode *temp = new ListNode();
            p->next = temp;
            p=p->next;
           }
        }
        while(l1){
            ListNode *temp = new ListNode();
            p->next = temp;
            p=p->next;
            p->val = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            l1 = l1->next;
        }
        while(l2){
            ListNode *temp = new ListNode();
            p->next = temp;
            p=p->next;
            p->val = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            l2 = l2->next;
        }
        if(carry){
            ListNode *temp = new ListNode();
            p->next = temp;
            p=p->next;
            p->val = carry;
        }
        return head;
    }
};