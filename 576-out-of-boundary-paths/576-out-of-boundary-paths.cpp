class Solution {
public:
    int mod = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<int>>vc(m,vector<int>(n,0));
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(startRow,startColumn,maxMove,m,n,dp);
        
    }
    int solve(int i,int j,int t,int m,int n,vector<vector<vector<int>>> &dp){
        
        if(i < 0 || i >= m  || j < 0 || j >= n){
            return 1;
        }
        if(t == 0) return 0;
        if(dp[t][i][j] != -1)
            return dp[t][i][j];
        long long int u = solve(i-1,j,t-1,m,n,dp);
        long long int l = solve(i,j-1,t-1,m,n,dp);
        long long int d = solve(i+1,j,t-1,m,n,dp);
        long long int r = solve(i,j+1,t-1,m,n,dp);
        return dp[t][i][j] = (u%mod+l%mod+r%mod+d%mod)%mod;
    }
};