class Solution {
public:
    int fn(int ind, int prev, int n, vector<int> &nums) {
        if (ind==n) return 0;
        int notTake=fn(ind+1, prev, n, nums);
        int take=0;
        if (nums[ind]> prev) take=1+fn(ind+1, nums[ind], n, nums);
        return max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //dp[i][n] states i..n-1 length of longest subsequence that can be made by selecting prev index as n
        //real prev index will be n+1 because we are mapping -1 (no element selected) to 0
        for (int i=n-1; i>=0; i--) {
            for (int prev=-1; prev<i; prev++) {
                int notTake=dp[i+1][prev+1];
                int take=0;
                if (prev==-1 || nums[prev]<nums[i]) take=1+dp[i+1][i+1];
                dp[i][prev+1]=max(take,notTake);
            }
        }
        return dp[0][0];   
    }
};