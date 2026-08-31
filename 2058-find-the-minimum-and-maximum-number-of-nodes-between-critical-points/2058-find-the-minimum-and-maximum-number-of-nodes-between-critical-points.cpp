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
    bool iscrit(int a,int b,int c){
        return (a>b && b<c)||(a<b && b>c);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *f = head, *s = head->next,*t = s->next;
        if(!t){
            return {-1,-1};
        }
        int mini = INT_MAX,maxi = 0;
        int minp = -1,maxp = -1;
        int i = 0,prev = 0;
        while(t){
            if(iscrit(f->val,s->val,t->val)){
                if(minp!=-1)mini=min(mini,i-prev);
                if(minp==-1)minp=i;
                maxi = i - minp;
                prev = i;
                cout<<minp<<" "<<i<<endl;
            }
            f=f->next;
            s=s->next;
            t=t->next;
            i++;
        }
        if(maxi == 0)return {-1,-1};
        return {mini,maxi};
    }
};