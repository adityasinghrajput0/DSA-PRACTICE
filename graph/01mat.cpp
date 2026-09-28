class Solution {
public:
    // int dfs (int row, int col, vector<vector<int>>& mat) {
    //     int rows=mat.size();
    //     int cols=mat[0].size();
    //     if (row<0 || row>=rows || col<0 || col>=cols)
    //     return 1e9;
    //     if (!mat[row][col]) return 0;
    //     if (mat[row][col]==-1) return 1e9;
    //     mat[row][col]=-1;
    //     int mindis=min({1+dfs(row-1,col,mat),1+dfs(row,col-1,mat),
    //     1+dfs(row+1,col,mat),1+dfs(row,col+1,mat)});
    //     mat[row][col]=1;
    //     return mindis;
    // }

    // bfs technique is more efficient as it traverse level wise and find distance in less time.
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols,-1));
        queue<pair<int,int>> q;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (!mat[i][j]) {
                    q.push({i,j});   
                    dist[i][j]=0;
                }
            }
        }
        int layers=1;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,-1,0,1};
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; i++) {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for (int j=0; j<4; j++) {
                    int nrow=row+delrow[j]; 
                    int ncol=col+delcol[j];
                    if (nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && mat[nrow][ncol]==1 && dist[nrow][ncol]==-1) {
                        dist[nrow][ncol]=layers;
                        q.push({nrow,ncol});
                    }
                }
            }
            layers++;
        }
        return dist;
    }
};