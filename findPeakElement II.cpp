class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int col, int row) {
        int max=INT_MIN;
        int maxRow=INT_MIN;
        for (int i=0; i<row; i++) {
            if (mat[i][col]>max){
                max=mat[i][col];
                maxRow=i;
            } 
        }
        return maxRow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;
        while (low<=high) {
            int mid=(low+high)/2;
            int row=maxElement(mat, mid, m);
            int left=(mid-1>=0)?mat[row][mid-1]:-1;
            int right=(mid+1<n)?mat[row][mid+1]:-1;
            if (mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if (mat[row][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};