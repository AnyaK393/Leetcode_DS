class Solution {
public:

    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {

        if(root == NULL) {
            return NULL;
        }

        // First visit larger values
        bstToGst(root->right);

        // Add current value to running sum
        sum += root->val;
        root->val = sum;

        // Then visit smaller values
        bstToGst(root->left);

        return root;
    }
};