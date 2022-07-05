class Solution {
public:
    int minDistance(string word1, string word2) {
        
   
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0; i<m; i++) dp[0][i] = 0;
        for(int i=0; i<n; i++) dp[i][0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                 if(word1[i - 1] == word2[j - 1])
                    dp[i][j] =  1 + dp[i-1][j-1];
        
                else
                    dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // int z = solve(n,m,word1,word2,dp);
        int k = m + n - dp[n][m]*2;
        return k;
        
    }
    
    
    int solve(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        
        if(i == 0 || j == 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i - 1] == s2[j - 1])
            return dp[i][j] =  1 + solve(i-1,j-1,s1,s2,dp);
        
        else
            return dp[i][j] =  max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
    
};