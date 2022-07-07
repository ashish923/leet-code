class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i= s1.length(),j = s2.length(), k = s3.length();
        
        if(k != i + j)
            return false;
        vector<vector<int>>dp(105, (vector<int>(105, -1)));
        return solve(s1,s2,s3,0,0,0,dp);
        
    }
    
    bool solve(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>> &dp){
     
        
        if(i >= s1.size() && j >= s2.size() && k >= s3.size()){
            return 1;
        }
        if( dp[i][j] != -1)
            return dp[i][j];
       int ans = 0;
        if(i < s1.size() && s3[k] == s1[i])
            ans |= solve(s1,s2,s3,i+1,j,k+1,dp);
        if(j < s2.size() && s3[k] == s2[j])
            ans |= solve(s1,s2,s3,i,j+1,k+1,dp);
        
        return dp[i][j] = ans;
            
        
        
    }
};