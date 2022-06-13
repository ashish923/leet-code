class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
       vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        
        return solve(0,0,m,triangle,dp);
    }
    
    int solve(int i,int j,int m,vector<vector<int>>& arr,vector<vector<int>>& dp){
        
        if(i==m-1) return arr[i][j];
        if(i>=m) return 1e8;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int down = arr[i][j] + solve(i+1,j,m,arr,dp);
        int diagonal_down = arr[i][j] + solve(i+1,j+1,m,arr,dp);
        return dp[i][j] = min(down,diagonal_down);
    }
};