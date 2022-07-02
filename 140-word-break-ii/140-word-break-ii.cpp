class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
          
        unordered_set<string> st;
        for(auto x : wordDict){
            
            st.insert(x);
        }
        vector<int> dp(s.size()+1,-1);
        string ansstr = "";
        vector<string> res;
        solve(st,s,0,ansstr,res);
        return res;
        
    }
    
    void solve(unordered_set<string>& str, string s, int id, string ansstr,vector<string> &res){
        
        if(id == s.size())
        {
            ansstr.pop_back();
            res.push_back(ansstr);
            return ;
            
        }
        
        string sr = "";
        for(int i = id; i<s.length(); i++){
            
            sr.push_back(s[i]);
            
            if(str.find(sr) != str.end()){
                solve(str,s,i+1,ansstr + sr + " ",res);
            }
  
        }
       
        
    }
};