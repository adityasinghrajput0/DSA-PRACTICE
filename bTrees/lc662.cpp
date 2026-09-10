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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long>> q;
        long ans=1;
        q.push({root,0});
        while (!q.empty()) {
            int size=q.size();
            int sub=q.front().second; //first index of each level 
            long first, last;
            for (int i=0; i<size; i++) {
                TreeNode* node=q.front().first;
                long curr_ind=q.front().second-sub; // re-indexing of each level starting from zero
                q.pop();
                if (i==0) first=curr_ind; //leftmost node
                if (i==size-1) last=curr_ind; //rightmost node
                if (node->left) q.push({node->left,2*curr_ind+1});
                if (node->right) q.push({node->right,2*curr_ind+2});
            }
            ans=max(ans,last-first+1); //track the max width
        }
        return (int)ans;
    }
};