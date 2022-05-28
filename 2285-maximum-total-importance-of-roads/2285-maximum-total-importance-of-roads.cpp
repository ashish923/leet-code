class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        int nn = roads.size();
        vector<int> mp(n,0);
        for(int i=0; i<nn; i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        sort(mp.begin(),mp.end());
        long long int s =0;
       for(int i=0; i<n; i++){
           s += (long long)mp[i]*(i+1);
       }
        
        return s;
        
        
        
    }
};