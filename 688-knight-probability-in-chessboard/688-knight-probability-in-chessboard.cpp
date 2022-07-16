class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        int count  = 0;
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n, vector<double>(n, -1)));
        double z = solve(row,column,n,k,dp);
        
        return z;
        
    }
    
    
    double solve(int i,int j,int n,int k,vector<vector<vector<double>>> &dp){
       
        
        if(k<0)return 0.0;
        if(i<0 || i >= n || j<0 || j>=n) return 0.0;
        if(k==0) return 1.0;
        if(dp[k][i][j] != -1)
            return dp[k][i][j];
        double ul = solve(i-2,j-1,n,k-1,dp);
        double ull = solve(i-1,j-2,n,k-1,dp);
        
        double ur = solve(i-2,j+1,n,k-1,dp);
        double urr = solve(i-1,j+2,n,k-1,dp);
        
        double dl = solve(i+2,j-1,n,k-1,dp);
        double dll = solve(i+1,j-2,n,k-1,dp);
        
        double dr = solve(i+2,j+1,n,k-1,dp);
        double drr = solve(i+1,j+2,n,k-1,dp);
        
        return dp[k][i][j] = (double)(ul+ull+ur+urr+dr+drr+dl+dll)/8.0;
    }
};