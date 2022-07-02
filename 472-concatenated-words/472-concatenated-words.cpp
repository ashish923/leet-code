class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> st;
        for(int j=0; j<words.size(); j++){
            string s = words[j];
            st.insert(s);
        }
        vector<string> res;
        string sr = "";
        for(int j=0; j<words.size(); j++){
            string s = words[j];
            int i=0,k =0,t=0;
            
            if(solve(st,s,i,t) > 1 )
                res.push_back(s);
        }
        
        return res; 
    }
    
   int solve(unordered_set<string>& str,string s,int id ,int t){
       
       
       if(id == s.length())
       {
           return 1;
       }
       
       string ans = "";
       int res = 0;
       for(int i=id; i<s.length(); i++){
           ans += s[i];
           
           if(str.count(ans) ) {
               
               res += solve(str,s,i+1,t++);
               }
               
       }
       
       return res;
        
    }  
        
};