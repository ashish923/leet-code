class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        map<int,vector<int>> mp;
      
        for(int i=0; i<n; i++){
            int z = candidates[i];
            vector<int> vc;
              int j=1;
            while(z!=0){
            if((z&1)==1)
                mp[j].push_back(candidates[i]);    
            // else
            //     vc.push_back(0);    
              z = z>>1;
                
                j++;
        }
            
            // int g = vc.size();
            // int r = 1;
            // for(int i = g-1; i>=0; i--){
            //     if(vc[i] == 1)
            //         mp[r].push_back(candidates[i]);
            //     r++;
            // }  
        }
        int l = 0;
        for(auto x : mp){
            if(x.second.size()>l){
                l = x.second.size();
            }
        }
        cout<<l;
        return l;
        
//         for(auto x : mp){
//             if(x.second.size() == l){
//                 return x.second;
//             }
//         }
        
//         return {};
        
    }
};