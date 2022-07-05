class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        // top down approach with O(n*m) time
        // passed all test cases 
        for(int i=1; i<=n1; i++){
            
            for(int j=1; j<=n2; j++){
                
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
    }
    // recursive solution bottom up approach
    // which gives tle at 44th the last test case fuckkk i dont know how    
    int solve(string s1, string s2,int n,int k,vector<vector<int>>& dp){
        
        
        if(n<0||k<0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        if(s1[n] == s2[k]){
          dp[n][k] = (1+solve(s1,s2,n-1,k-1,dp));
        }
        else{
            
           dp[n][k] = max(solve(s1,s2,n-1,k,dp),solve(s1,s2,n,k-1,dp));
        }
        return dp[n][k];
    }
};