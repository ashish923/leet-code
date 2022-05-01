class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        
        unordered_set<string> st;
        string str = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            str += s[i];
            st.insert(str);
        }
        int i=0,cnt=0;
       for(int i=0; i<words.size();i++){
           str = words[i];
           if(st.find(str) != st.end()){
               cnt++;
           }
       }
     return cnt;   
    }
};