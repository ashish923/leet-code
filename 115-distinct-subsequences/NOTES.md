​
​
recur + memo O(n*m)
int solve(string s1,string s2,int i,int j,vector<vector<int>> &dp){
//  that means 2nd string gets exhaust the req string is present in 1st string
if(j == 0) return 1;
//there is no string left to check
if(i == 0) return 0;
if(dp[i][j] != -1)
return dp[i][j];
//  we can take the char or we can not take the char
if(s1[i-1] == s2[j-1]){
return dp[i][j] = solve(s1,s2,i-1,j-1,dp) + solve(s1,s2,i-1,j,dp);
}
//strings char didint match
else return dp[i][j] = solve(s1,s2,i-1,j,dp);
}
tabulation  o(n*m)
for(int i=0; i<=m; i++) dp[0][i] = 0;
for(int i=0; i<=n; i++) dp[i][0] = 1;
​
​
for(int i=1; i<=n; i++){
for(int j=1; j<=m; j++){
if(s[i - 1] == t[j - 1])
dp[i][j] =  dp[i-1][j-1]  + dp[i-1][j];
​
else
dp[i][j] =  dp[i-1][j];
}
}
using 2 array of space o(n)
vector<double> prev(m+1,0), curr(m+1,0);
prev[0] = curr[0] = 1;
for(int i=1; i<=n; i++){
for(int j=1; j<=m; j++){
if(s[i - 1] == t[j - 1])
curr[j] =  prev[j-1]  + prev[j];
else
curr[j] =  prev[j];
}
prev = curr;
}
return prev[m]