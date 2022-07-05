class Solution {
public:
    vector<string> generateParenthesis(int n) {
         int id = 0;
        vector<string> res;
        int i=n; int j=n;
        solve(n,res,i,j,"");
        return res; 
    }
    
    
    void solve(int n,vector<string> &res,int i,int j,string s){ 
        if(i == 0 && j == 0)
        {res.push_back(s);
            return;
        }
        
        if(i > 0)
        {
            
            s.push_back('(');
            solve(n,res,i-1,j,s);
            s.pop_back();
           
        }
        
        if(i < j){
            s.push_back(')');
            solve(n,res,i,j-1,s);
            s.pop_back();
           
        }
        
    }
};