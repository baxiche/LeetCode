/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bulid(int* nums, int begin, int end){
    if (begin >= end) return NULL;
    
    int maxIdx = 0;
    int max = -1;
    for (int i = begin; i < end; ++i){
        if (nums[i] > max){
            maxIdx = i;
            max = nums[i];
        }
    }
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = max;
    root->left = bulid(nums, begin, maxIdx);
    root->right = bulid(nums, maxIdx + 1, end);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return bulid(nums, 0, numsSize);
}