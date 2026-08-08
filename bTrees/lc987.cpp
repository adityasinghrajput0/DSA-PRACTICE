/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right; nxb fhviygitukkpo
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal (TreeNode* root, map<int,map<int,multiset<int>>> &hash,int row, int col) {
        if (!root) return;
        hash[col][row].insert(root->val);
        traversal(root->left, hash, row+1,col-1);
        traversal(root->right, hash, row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int,map<int,multiset<int>>> hash;
        traversal(root, hash, 0, 0);
        for (auto col: hash) {
            vector<int> temp;
            for (auto row: col.second) {
                for (auto value:row.second) {
                    temp.push_back(value);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};