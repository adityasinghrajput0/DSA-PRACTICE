#include <stdio.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode* treenode;

treenode deleteNode (treenode root, int key) {
    if (root==NULL) return NULL;
    if (root->data==key) return helper(root);
    treenode dummy=root;
    while (root!=NULL) {
        if (key<root->data) {
            if (root->left!=NULL && root->left->data==key) {
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else {
            if (root->right!=NULL && root->right->data==key) {
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }
    return dummy;
}

treenode helper(treenode root) {
    if (root->left==NULL) return root->right;
    if (root->right==NULL) return root->left;
    treenode rightchild=root->right;
    treenode lastright=lastRight(root->left);
    lastright->right=rightchild;
    return root->left;
}

treenode lastRight(treenode root) {
    if (root->right==NULL) {
        return root;
    }
    return lastRight(root->right);
}