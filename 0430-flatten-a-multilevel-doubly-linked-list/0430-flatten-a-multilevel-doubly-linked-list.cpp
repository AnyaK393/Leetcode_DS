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
        if(head==nullptr){
            return head;
        }

        Node* curr= head;
        while(curr!=nullptr){
            if(curr->child!=nullptr){// childs exists
                Node* next= curr->next; //save 4 curr=3 next=4
                curr->next= flatten(curr->child);//3s child is 7 this will return head which is 7
                curr->next->prev= curr; //7s prev points to 3 
                curr->child=nullptr;

                //find tail
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                //attach tail to next ptr
                if(next!=nullptr){
                    curr->next=next;
                    next->prev=curr;
                }
            }
            else{
                curr=curr->next;
            }
        }
        return head;
        
    }
};