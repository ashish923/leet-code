class Solution {
public:
    
    long long int  mod = 1000000007;
    int countPaths(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        
        long long int s = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                s = (s + (dfs(grid,i,j,-1,dp)))%mod;
            }
        }
        
        return s;
    }
    
     int dfs(vector<vector<int>>& matrix,int i,int j,int p,vector<vector<int>> &dp){
        if(i<0 || i == matrix.size() || j<0 || j >= matrix[0].size() || p >= matrix[i][j])               return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int d = dfs(matrix,i+1,j,matrix[i][j],dp);
        int r =  dfs(matrix,i,j+1,matrix[i][j],dp);
        int u =  dfs(matrix,i-1,j,matrix[i][j],dp);
        int l =  dfs(matrix,i,j-1,matrix[i][j],dp);
        
        return dp[i][j] =  ((d%mod+r%mod+u%mod+l%mod)+1)%mod;   
    }
};