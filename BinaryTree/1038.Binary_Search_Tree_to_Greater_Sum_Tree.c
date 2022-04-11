/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum;

void tra(struct TreeNode* root){
    if (!root) return;
    
    tra(root->right);
    root->val += sum;
    sum = root->val;
    tra(root->left);
}

struct TreeNode* bstToGst(struct TreeNode* root){
    sum = 0;
    tra(root);
    return root;
}