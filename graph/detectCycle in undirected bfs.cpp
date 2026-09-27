class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        for (int i=0; i<edges.size(); i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=0; i<V; i++) {
            if (!visited[i]) { // there may be different components in a graph so you have to call bfs for each vertex.
                queue<pair<int,int>> q;
                q.push({i,i});
                        visited[i]=1;
                        while (!q.empty()) {
                            int node=q.front().first;
                            int parent=q.front().second;
                            q.pop();
                            for (int neighbour:adj[node]) {
                                if (!visited[neighbour]){
                                    visited[neighbour]=1;
                                    q.push({neighbour,node});
                                }
                                else if (neighbour!=parent) return true; //if a node is already visited and its not the parent of current 
                                //one then there is a cycle.
                            }
                        }
            }
        }
        return false;
    }
};

//dfs
class Solution {
  public:
    bool dfs (int node, vector<vector<int>> &adj, vector<int> &visited, vector<int>&parent) {
        visited[node]=1;
        for (int neighbour:adj[node]) {
            if (!visited[neighbour]) {
                parent[neighbour]=node;
                if(dfs(neighbour, adj, visited, parent)) return true;
            }
            else if (parent[node]!=neighbour) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        vector<int> parent(V,-1);
        for (int i=0; i<edges.size(); i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (dfs(i,adj,visited,parent)) return true;
            }
        }
        return false;
    }
};