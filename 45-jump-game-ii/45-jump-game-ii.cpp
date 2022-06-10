class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
    
    int solve(vector<int> &vc,int n,vector<int> &dp){
        
        if(n>=vc.size()-1) return 0;
        if(dp[n] != -1) return dp[n];
        int minn = 1e8;
        
        for(int i=1; i<=vc[n]; i++){
           minn = min(minn, 1+solve(vc, n+i,dp));
        }
        return dp[n] = minn;
        
    }
};