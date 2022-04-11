/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDia;

int maxDep(struct TreeNode* root){
    if (!root) return 0;
    
    int left = maxDep(root->left);
    int right = maxDep(root->right);
    maxDia = (maxDia > left + right)? maxDia : left + right;

    return 1 + ((left > right)? left : right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    maxDia = 0;
    maxDep(root);
    return maxDia;
}