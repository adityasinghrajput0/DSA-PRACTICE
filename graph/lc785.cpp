class Solution {
public:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph) {
        color[node]=col;
        int colr=(col==0)?1:0;
        for (int neighbour: graph[node]) {
            if (color[neighbour]==col) return false; //if adjacent node has same color
            // return false
            if (color[neighbour]==-1) {
                if(!dfs(neighbour,colr,color,graph)) return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1); //track color of adjacent nodes
        for (int i=0; i<n; i++) {
            if (color[i]==-1) {
                if (!dfs(i,0,color,graph)) return false; //we have to check bipartite
                // in all the components of graph therefore dont return true
                //here it will be only based on current graph component traversal
            }
        }
        return true;
    }
};