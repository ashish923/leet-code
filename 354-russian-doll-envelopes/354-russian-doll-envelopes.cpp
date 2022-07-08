class Solution {
public:
    
     static bool comp(vector<int> &a,vector<int> &b){
         if(a[0] == b[0])
             return a[1] > b[1];
         return a[0] < b[0];
     }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1; i<n; i++){
            if(temp.back() < envelopes[i][1])
                temp.push_back(envelopes[i][1]);
        
        else{
            int ind = lower_bound(temp.begin(),temp.end(),envelopes[i][1]) - temp.begin();
            temp[ind] = envelopes[i][1];
        }
        }
        return temp.size();
        

        
    }
    
    
//     memorization tc - o(nlogn + o(n^2)) TLE
    
      int solve(vector<vector<int>> &a,int prev,int curr,vector<vector<int>> &dp){
            
        if(curr == 0){
            return 0;
        }    
          
          if(dp[prev][curr] != -1)
              return dp[prev][curr];
          int take = 0,no_take;
          if(prev-1 == a.size()||(a[curr-1][0] > a[prev-1][0] && a[curr-1][1] > a[prev-1][1]))          {
                  take = 1 + solve(a,curr,curr-1,dp);
          }
          
          no_take = solve(a,prev,curr-1,dp);
           return dp[prev][curr] = max(take,no_take);    
     }
};