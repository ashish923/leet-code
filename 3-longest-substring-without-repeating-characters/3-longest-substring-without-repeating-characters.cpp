class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s == " "){
        //     return 0;
        // }
        
        int j=0,n = s.length();
//         for(int i=0; i<n; i++){
//             if(s[i] == ' ')
//                 return 1;
//         }
        
       
        int i = 0;
        vector<int> freq(257,0);
        int maxx = 0,c =0;
        while(j<n ){
            
            
            if(freq[(int)s[j]] == 0){
                freq[(int)s[j]]++;
                // cout<<s[j]<<" ";
                c++;j++;
                maxx = max(c,maxx);
            }
            
            else{
                // cout<<s[i];
                freq[(int)s[i]]--;
                i++;
                c--;
            }
        }
        
        return maxx;
        
    }
};