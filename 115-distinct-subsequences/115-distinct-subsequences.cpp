class Solution {
public:
    int numDistinct(string s, string t) {
        
        long long int n = s.size();
        long long int m = t.size();
        vector<double> prev(m+1,0);
        prev[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                 if(s[i - 1] == t[j - 1])
                    prev[j] =  prev[j-1]  + prev[j];  
            }
          
        }
       
        return prev[m];
        
    } 
};