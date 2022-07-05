class Solution {
public:
    
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size();
        int maxx = 0,p;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                p = matrix[i][j];
                
                
                maxx = max(maxx,dfs(matrix,i,j,-1));
                
                
            }
        }
        
       return maxx; 
    }
    
    int dfs(vector<vector<int>>& matrix,int i,int j,int p){
        
        if(i<0 || i >=matrix.size() || j<0 || j >= matrix[0].size() || p >= matrix[i][j])             return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int d = dfs(matrix,i+1,j,matrix[i][j]);
        int r =  dfs(matrix,i,j+1,matrix[i][j]);
        int u =  dfs(matrix,i-1,j,matrix[i][j]);
        int l =  dfs(matrix,i,j-1,matrix[i][j]);
        
        return dp[i][j] =  max({d,r,u,l}) + 1;
        
        
    }
};