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
 //core idea if left height is equal to right then its a complete binary tree and we can calculate
 //total no. of nodes easily
class Solution {
public:
    long myPow(long base, long exp) {
        long N=exp;
        if (N==0) return 1;
        if (N%2==0) return myPow(base*base,exp/2);
        return base*myPow(base*base,(exp-1)/2);
    }
    int lh(TreeNode* temp) {
        int h=1;
        while (temp->left) {
            temp=temp->left;
            h++;
        }
        return h;
    }
    int rh(TreeNode* temp) {
        int h=1;
        while (temp->right) {
            temp=temp->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lefth=lh(root);
        int righth=rh(root);
        if (lefth==righth) return myPow(2,lefth)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};