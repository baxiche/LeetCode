/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root){
    if (!root) return;
    
    flatten(root->left);
    flatten(root->right);
    
    struct TreeNode* cur = root->left;
    if (!cur) return;
    while (cur->right) cur = cur->right;
    cur->right = root->right;
    root->right = root->left;
    root->left = NULL;
    
    return;
}