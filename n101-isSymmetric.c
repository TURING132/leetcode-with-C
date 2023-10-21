#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode* p, struct TreeNode* q){
    if(!p&&!q)return true;
    if(!p||!q)return false;
    return p->val==q->val && helper(p->left,q->right) && helper(p->right,q->left);
}

bool isSymmetric(struct TreeNode* root){
    return helper(root,root);
}