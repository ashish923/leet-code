class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int a : nums){
            s += a;
        }
        if(s%2 != 0)
            return 0;
        s = s/2;

        
            vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        // cout<<solve
           bool z = solve(nums,n,s,dp);
        cout<<z;
        return z;
    }
    
    int solve(vector<int>& nums,int n,int t,vector<vector<int>> &dp){
        if(n<=0) return false;
        if(t == 0) return true;
        
        if(dp[n][t] != -1)
            return dp[n][t];
      
        if(t >= nums[n-1])
            return dp[n][t] = solve(nums,n-1,t-nums[n-1],dp)||solve(nums,n-1,t,dp);
        
        else return dp[n][t] = solve(nums,n-1,t,dp);
       
    }
};