class Solution {
public:
    int minDistance(string word1, string word2) {
        
   
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int z = solve(0,0,word1,word2,dp);
        int k = m + n - z*2;
        return k;
        
    }
    
    
    int solve(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        
        if(i == s1.length() || j == s2.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(i+1,j+1,s1,s2,dp);
        }
        else
            return dp[i][j] =  max(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
    }
    
};