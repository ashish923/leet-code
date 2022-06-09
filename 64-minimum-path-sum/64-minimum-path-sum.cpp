class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)); 
        return solve1(0,0,m,n,grid,dp);
        
    }
    
    int solve1(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>> &dp ){
        
        if(i==n-1 && j==m-1) return arr[i][j];
        if(i<0 || i >= n || j<0 || j >= m) return 1e8;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = min(arr[i][j] +solve1(i+1,j,n,m,arr,dp),arr[i][j] + solve1(i,j+1,n,m,arr,dp));
    }
    
    int solve(int i,int j,int m,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
        
        if(i==0&&j==0) return arr[i][j];
        if(i<0||j<0) return 1e8;
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = min(arr[i][j]+solve(i,j-1,m,n,arr,dp),arr[i][j]+solve(i-                     1,j,m,n,arr,dp));
    }
};