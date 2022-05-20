class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,m,n,obstacleGrid,dp);
    }
    int solve(int i,int j,int m,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i>=0&&j>=0 && arr[i][j]==1 ) return 0;
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i-1,j,m,n,arr,dp)+solve(i,j-1,m,n,arr,dp);
    }
};