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
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar){
        if(root==nullptr){
            return 0;
        }
        int good = (root->val >= maxSoFar) ? 1 : 0;

        maxSoFar= max(root->val, maxSoFar);

        int left= dfs(root->left, maxSoFar);
        int right=dfs(root->right, maxSoFar);

        return good+left+right;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};