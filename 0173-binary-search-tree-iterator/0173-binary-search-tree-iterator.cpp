/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;

    // Push the node and all its left children into the stack
    void StoreLeftNodes(TreeNode* root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    // Constructor
    BSTIterator(TreeNode* root) {
        // Start by storing the leftmost path
        StoreLeftNodes(root);
    }

    // Return the next smallest element
    int next() {
        // Top of stack is the smallest remaining node
        TreeNode* ans = s.top();
        s.pop();

        // After taking this node, we need to process
        // its right subtree
        StoreLeftNodes(ans->right);

        return ans->val;
    }

    // Check if there are more nodes left
    bool hasNext() {
        return s.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */