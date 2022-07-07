class Solution {
public:
    int c =0,s=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<vector<int>>dp(3006,vector<int>(3006,-1));
        return solve(nums,target,0,dp);
        
    }
    
    int solve(vector<int>& nums,int t,int i,vector<vector<int>> &dp){
        
       if(i == nums.size()) 
        {
           if(t == 0 )
                return 1;
           return 0;
        }
        if(dp[i][1000+t] != -1)
            return dp[i][1000+t];
        
        int add = solve(nums,t+nums[i],i+1,dp);
        int sub = solve(nums,t-nums[i],i+1,dp);
        return dp[i][1000 + t] = add+sub;
    }
};