class Solution {
public:
    vector<int> dp;
    int cost_function(vector<int>& cost,int n){
        if(n==0||n==1) return cost[n];
        if(n<0) return 0;
        // dp[n+1];
        if(dp[n]!=0) return dp[n];
        
        return dp[n] =cost[n] + min(cost_function(cost,n-1),cost_function(cost,n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,0);
        return  min(cost_function(cost,n-1),cost_function(cost,n-2));
        
    }
    
    
};