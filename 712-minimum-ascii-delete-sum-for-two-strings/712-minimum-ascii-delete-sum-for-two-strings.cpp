class Solution {
public:
    int minimumDeleteSum(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int s =0;
        for(int i=0; i<n; i++) s += (int)word1[i];
        for(int i=0; i<m; i++) s += (int)word2[i];
         for(int i=0;i<=n;i++)
       { 
           for(int j=0;j<=m;j++)
               {if(i==0 || j==0) {dp[i][j]=0; continue;}
                if(word1[i-1]==word2[j-1]) dp[i][j]=int(word1[i-1])+ dp[i-1][j-1];
                else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
       }
        
        return s - dp[n][m]*2;
    
    }
    
    int solve(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = (int)s1[i] + solve(i-1,j-1,s1,s2,dp);       
            return dp[i][j] =  max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
};