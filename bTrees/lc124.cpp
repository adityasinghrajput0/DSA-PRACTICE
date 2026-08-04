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
    int sum(TreeNode* root, int &maxsum) {
        if (root == NULL) return 0;
        int left=sum(root->left,maxsum);
        int right=sum(root->right,maxsum);
        if (left>0 && right>0) maxsum=max(maxsum,root->val+(left+right)); //if both left and right nodes are
        // positive maxsum will be a result of left, right and current root .
        else if (left<0 && right<0) { //if both left and right are negative maxsum should be compared with root only
            maxsum=max(maxsum,root->val);
            return root->val;
        }
        else maxsum=max(maxsum,root->val+max(left,right)); //otherwise we will take max of left and right and sum it to currentroot.
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=root->val;
        sum(root,maxSum);
        return maxSum;
    }
};