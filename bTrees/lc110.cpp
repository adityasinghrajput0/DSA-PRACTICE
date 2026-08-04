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

 //the core idea is if at any node abs diff of left and right is greater than 1 return -1
 //otherwise return the height 
 //compare the result to answer true or false;
class Solution {
public:
    int height (TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        if (left==-1) return -1;
        int right = height(root->right);
        if (right==-1) return -1;
        if (abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return (height(root) != -1);
    }
};