/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//a tree cant move upward so make a map of parent for upward traversal
class Solution {
public:
    void dfs (TreeNode* root, unordered_map<TreeNode*,TreeNode*> &hash) { //mark parent of each node
        if (root->left) {
            hash[root->left]=root;
            dfs(root->left,hash);
        }
        if (root->right) {
            hash[root->right]=root;
            dfs(root->right,hash);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> hash;
        unordered_map<TreeNode*,bool> visited; //track visited nodes
        dfs(root,hash);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dis=0; //use dis variable to radially traverse in tree and record nodes at diff distance from target
        while (!q.empty()) {
            int size=q.size();
            if (dis==k) break;
            for (int i=0; i<size; i++) {
                auto top=q.front();
                q.pop();
                if (hash.find(top)!=hash.end() && !visited[hash[top]]) {
                    q.push(hash[top]);
                    visited[hash[top]]=true;
                }
                if (top->left && !visited[top->left]) {
                    q.push(top->left);
                    visited[top->left]=true;
                }
                if (top->right && !visited[top->right]) {
                    q.push(top->right);
                    visited[top->right]=true;
                }
            }
            dis++;
        }
        vector<int> res;
        while (!q.empty()) {
            auto top=q.front(); q.pop();
            res.push_back(top->val);
        }
        return res;
    }
};