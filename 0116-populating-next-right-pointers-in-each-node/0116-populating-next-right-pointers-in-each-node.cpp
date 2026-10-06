/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        // If tree is empty or there is no left child,
        // there is nothing to connect
        if(root == NULL || root->left == NULL) {
            return root;
        }

        queue<Node*> q;

        // Start BFS with root
        q.push(root);

        // NULL marks the end of the current level
        q.push(NULL);

        // prev stores the previous node of the
        // current level
        Node* prev = NULL;

        while(q.size() > 0) {

            Node* curr = q.front();
            q.pop();

            // NULL means current level is finished
            if(curr == NULL) {

                // If queue is empty, there are no more levels
                if(q.size() == 0) {
                    break;
                }

                // Mark the end of the next level
                q.push(NULL);

                // IMPORTANT:
                // Reset prev because we are starting
                // a completely new level
                prev = NULL;
            }

            else {

                // Add left child to queue
                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                // Add right child to queue
                if(curr->right != NULL) {
                    q.push(curr->right);
                }

                // Connect previous node to current node
                if(prev != NULL) {
                    prev->next = curr;
                }

                // Current node becomes previous node
                // for the next node in this level
                prev = curr;
            }
        }

        return root;
    }
};