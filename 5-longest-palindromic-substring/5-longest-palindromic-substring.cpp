class Solution {
public:
    bool f = true;
    string longestPalindrome(string s) {
        
        int n = s.size();
        int maxx = 0; 
        int start = 0, end = 0;
       for(int i=0; i<n; i++){
           
           int len1 = checkpal(s,i,i);
           int len2 = checkpal(s,i,i+1);
           int z = max(len1,len2);
           if(z > end - start){
                start = i - (z-1)/2;
                end = i + z/2;
           } 
       }
        return s.substr(start, end + 1 - start);
    }
    
    
     int checkpal(string str,int i,int j){
         
         while( i >= 0 && j < str.size() && str[i] == str[j]){
             i--;j++;
         }
         
         return j - i - 1;
     }  
        
};