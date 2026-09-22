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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int maxSum = INT_MIN;
        int ans = 1;

        while(q.size() > 0) {

            int size = q.size();
            int sum = 0;

            // Process all nodes of current level
            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            // Check if current level has maximum sum
            if(sum > maxSum) {
                maxSum = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};