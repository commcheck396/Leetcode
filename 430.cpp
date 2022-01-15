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
        int i,k,b,c;
        stack <Node*> a;
        Node *position,*POSITION,*tmp;
        POSITION=head;
        position=head;
        for(;position!=nullptr;position=position->next){
            if(position->child!=nullptr){
                if(position->next)a.push(position->next);
                position->next=position->child;
                position->next->prev=position;
                position->child=nullptr;
            }
            if(position->next==nullptr&&!a.empty()){
                tmp=a.top();
                a.pop();
                position->next=tmp;
                tmp->prev=position;
            }
        }   
        return head; 
    }
};