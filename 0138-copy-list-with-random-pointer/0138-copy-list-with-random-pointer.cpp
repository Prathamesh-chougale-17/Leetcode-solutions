/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node *temp = head, *st = new Node(head->val),*t = st;
        unordered_map<Node*, Node*> um,cm;
        while(temp){
            um[temp] = temp->random;
            temp = temp->next;
        }
        temp = head;
        while(temp && temp->next){
                Node *tmp = new Node(temp->next->val);
                t->next = tmp;
                t = t->next;
                temp = temp->next;
        }
        temp = head;
        t = st;
        while(temp){
            cm[temp] = t;
            t = t->next;
            temp = temp->next;
        }
        temp = head;
        t = st;
        while(t){
            if(um[temp]!=nullptr){
                t->random = cm[um[temp]];
            }
            t=t->next;
            temp = temp->next;
        }
        // while(temp){
        //     um[temp->random]=temp;
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp){
        //     if(um.find(temp)==um.end()){
        //         s = temp;
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // Node* st = new Node(temp->val);
        // temp = st;
        // while(temp){
        //     st->next = temp->random;
        //     temp = temp->next;
        // }
        return st;
    }
};