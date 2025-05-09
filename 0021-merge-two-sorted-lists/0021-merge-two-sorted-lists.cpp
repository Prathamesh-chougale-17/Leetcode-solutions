class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to start the merged list
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(list1 && list2){
            if(list1->val>list2->val){
                tail->next = list2;
                list2 = list2->next;
            }else{
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1:list2;
        return head->next;
    }
};
