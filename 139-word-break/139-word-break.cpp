class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        for(auto x : wordDict){
            
            st.insert(x);
        }
        vector<int> dp(s.size()+1,-1);
        return solve(st,s,0,dp);
        
    }
    
    bool solve(unordered_set<string>& str,string s,int id , vector<int> &dp){
        
        if(id == s.length()) return true;
        
        if(dp[id] != -1)
            return dp[id];
        
        int s_size = s.length();
        string sr = "";
        
        for(int i=id; i<=s_size; i++){
            sr += s[i];
            if((str.find(sr) != str.end()) && solve(str,s,i+1,dp)){
                  dp[id] = 1;
                return dp[id];
                // break;
            }
            
        }
        dp[id] = 0;
        return dp[id];
        
    }
};