class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
        
    }
    
    
    int solve(vector<int>& nums, int n,vector<int> &dp){
        
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1)
            return dp[n];
        int res = 0;
        for(int a : nums){
            if(a<=n){
            res += solve(nums,n-a,dp);
            }
        }
        return dp[n] = res;
    }
    
    
    
};