class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        map<int,int>mp;
        for(int i=0; i<edges.size(); i++){
            
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        
        int z = mp.size();
        // cout<<z;
        for(auto x : mp){
            // cout<<x.second<<" ";
            if(x.second == z-1){
                return x.first;
            }
        }
        
        
        return 0;
        
    }
};