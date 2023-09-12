#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int *)malloc(sizeof(int)*101);
    *returnSize = 0;
    poster(root,returnSize,result);
    return result;
}

void poster(struct TreeNode* root, int *returnSize, int* result){
    if(root==NULL)return;
    poster(root->left,returnSize,result);
    poster(root->right,returnSize,result);
    result[(*returnSize)++]=root->val;
}