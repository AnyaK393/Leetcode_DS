class Solution {
public:

    int search(vector<int>& inorder, int left, int right, int val) {

        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int& postIdx, int left, int right) {

        // No elements in this range
        if(left > right) {
            return NULL;
        }

        // Postorder: last element is the root
        TreeNode* root = new TreeNode(postorder[postIdx]);

        // Find root in inorder
        int inIdx = search(inorder, left, right, postorder[postIdx]);

        // Move backwards in postorder
        postIdx--;

        // IMPORTANT:
        // Since we are moving backwards:
        // right subtree comes FIRST
        root->right = helper(inorder, postorder,
                             postIdx, inIdx + 1, right);

        root->left = helper(inorder, postorder,
                            postIdx, left, inIdx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIdx = postorder.size() - 1;

        return helper(inorder, postorder,
                      postIdx, 0, inorder.size() - 1);
    }
};