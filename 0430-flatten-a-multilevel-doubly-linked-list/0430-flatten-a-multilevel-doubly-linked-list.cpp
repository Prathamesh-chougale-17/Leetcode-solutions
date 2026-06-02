/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* p = head;
        while(p){
            if(p->child){
                if(p->next){
                    st.push(p->next);
                }
                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;
            }
            if(!p->next && !st.empty()){
                p->next = st.top();
                st.top()->prev = p;
                st.pop();
            }
            p = p->next;
        }
        return head;
    }
};