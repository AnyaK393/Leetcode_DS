class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        // Create first node
        Node* newHead = new Node(head->val);

        m[head] = newHead;

        // First pass: create all copied nodes
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        while(oldTemp != NULL) {

            Node* copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Second pass: connect random pointers
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL) {

            if(oldTemp->random != NULL) {
                newTemp->random = m[oldTemp->random];
            }

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};