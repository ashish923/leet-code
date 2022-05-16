class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        // map<vector<int>,string> st;
        int n = words.size();
        vector<string> vcc; 
        vector<int> vcr(26,0);

        int t =1;
        for(int i=0; i<n; i++){
            string str = words[i];
            
            if(t==1){
            vector<int> vc(26,0);
                
            int j = 0;
                
            while(j<str.length()){
                vc[str[j] - 'a']++;
                j++;
            }
                int f =0;
            for(int i=0; i<26; i++) {
                if(vc[i] != vcr[i])
                {f = 1;
                 break;
                } 
            }
            if(f==1) {
                vcc.push_back(str);
                vcr = vc;
            }       
            } 
        }
        
        return vcc;
    }
};
