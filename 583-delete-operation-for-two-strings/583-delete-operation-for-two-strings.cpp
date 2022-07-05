class Solution {
public:
    int minDistance(string word1, string word2) {
        
   
        int n = word1.length();
        int m = word2.length();
//         column length vector
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0; i<=m; i++) prev[i] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                 if(word1[i - 1] == word2[j - 1])
                    curr[j] =  1 + prev[j-1];
                else
                    curr[j] =  max(prev[j],curr[j-1]);
                
            }
            prev = curr;
        }
        // int z = solve(n,m,word1,word2,dp);
        int k = m + n - prev[m]*2;
        return k;
        
    }
//     code for memo
//     after shitin  of index 
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