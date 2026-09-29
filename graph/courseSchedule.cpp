//if there is a cycle in course scheduling you cant complete courses.

class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfsvis, vector<vector<int>> &adj) {
        visited[node]=1;
        dfsvis[node]=1;
        for (int neighbour:adj[node]) {
            if (!visited[neighbour]) {
                if(dfs(neighbour, visited, dfsvis, adj)) return true;
            }
            else if (dfsvis[neighbour]) return true; // if there is a node which
            //is already visited in current flow it means there is a cycle.
        }
        dfsvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> visited(numCourses,0); //visited array tracks visited nodes
        vector<int> dfsvis(numCourses,0); //it tracks vertices visited in current flow
        vector<vector<int>> adj(numCourses);
        for (int i=0; i<n; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i=0; i<numCourses; i++) {
            if (!visited[i]) {
               if(dfs(i,visited,dfsvis,adj)) return false;
            }
        }
        return true;
    }
};