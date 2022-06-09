class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,dungeon,dp);
        
    }
    
    int solve(int i,int j,int n,int m,vector<vector<int>>& arr, vector<vector<int>> &dp){
        
        if(i == n-1 && j == m-1)   
            return (arr[i][j] <= 0) ? -arr[i][j] + 1 : 1;
        if(i==n || j==m) return 1e8;
        if(dp[i][j] != -1) return dp[i][j];
        // cout<<i<<" "<<j<<"\n";
        int down = solve(i+1,j,n,m,arr,dp);
        int rt = solve(i,j+1,n,m,arr,dp);
        
        int health;
       health = min(down,rt) - arr[i][j];
        // cout<<health<<"\n";
        // cout<<arr[i][j]<<"\n";
        // cout<<down<<"\n";
        // cout<<rt<<"\n";
      return dp[i][j] = ( health <= 0 ) ? 1 : health;
        
    }
};