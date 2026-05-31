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
    ListNode* insertionSortList(ListNode* head) {
         ListNode *left = head;
         while(left->next){
            ListNode *right = left->next;
            while(right){
                if(left->val>right->val)swap(left->val,right->val);
                right = right->next;
            }
            left = left->next;
         }
         return head;
    }
};