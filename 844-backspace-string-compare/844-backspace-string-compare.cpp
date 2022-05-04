class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        
        int n = s.size()-1,j = t.size()-1;
        string str = "",str1 = "";
        int c =0;
        for(int i=n; i>=0; i--){
            // cout<<c;
            if(s[i] =='#')
            { c++;}
            else if(c>0){
             
                
                c--;
            }
            else {
                str += s[i];
               
            }
        }
        n = j;
        j=0;
        for(int i=n; i>=0; i--){
            if(t[i] =='#')
                j++;
            else if(j>0){
                 j--;
            }
            else {
               str1 += t[i];
            }
        }
        cout<<str<<" "<<str1;
        if(str==str1) return true;
        return false;
        
    }
};