/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int res;
int idx;
int kk;

void traverse(struct TreeNode* root){
    if (!root) return;
    traverse(root->left);
    ++idx;
    if (idx == kk){
        res =  root->val;
        return;
    }
    traverse(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    idx = 0;
    kk = k;
    traverse(root);
    return res;
}
// @lc code=end

