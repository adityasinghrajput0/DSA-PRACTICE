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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0; //base case if there is no root return 0;
        int left=maxDepth(root->left); // calculate roots left depth
        int right=maxDepth(root->right);// calculate right depth
        return 1+max(left,right); //add current depth with the max of left and right;
    }
};