class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        // first  -> node
        // second -> index of node
        queue<pair<TreeNode*, unsigned long long>> q;

        if(root == NULL) {
            return 0;
        }

        q.push({root, 0});

        unsigned long long maxwidth = 0;

        while(q.size() > 0) {

            // Number of nodes in current level
            int currLevelSize = q.size();

            // Index of first and last node of current level
            unsigned long long startIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            // Width = last index - first index + 1
            maxwidth = max(maxwidth, endIdx - startIdx + 1);

            // Process current level
            for(int i = 0; i < currLevelSize; i++) {

                TreeNode* curr = q.front().first;
                unsigned long long currIdx = q.front().second;

                q.pop();

                // Left child
                if(curr->left != NULL) {
                    q.push({
                        curr->left,
                        currIdx * 2 + 1
                    });
                }

                // Right child
                if(curr->right != NULL) {
                    q.push({
                        curr->right,
                        currIdx * 2 + 2
                    });
                }
            }
        }

        return (int)maxwidth;
    }
};