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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head,*pnext = head->next;
        while(pnext){
            ListNode *temp = new ListNode(__gcd(p->val,pnext->val));
            p->next = temp;
            temp->next = pnext;
            p = pnext;
            pnext = pnext->next;
        }
        return head;
    }
};