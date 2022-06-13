class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        

       
        vector<int> vis(n+1,-1);
        vector<vector<int>> adj(n+1); 
           for(auto i:dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);            
        } 
        for(int i=1; i<n+1; i++){
            if(vis[i] == -1){
                 if(!bipartite_dfs(adj,vis,i)) return false;
            }
        }
        
        return true;
        
    }
    
    bool bipartite_dfs(vector<vector<int>>& grid, vector<int> &vis, int i){
        
        if(vis[i] == -1) vis[i] = 1;
        
        for(auto a : grid[i]){
            if(vis[a] == -1){
                vis[a] = 1 - vis[i];
              
                if(!bipartite_dfs(grid,vis,a)) 
                    return false;
            
            }
            else if(vis[a] == vis[i]){
             cout<<a<<" "<<i<<" ";
                return false;
            }
        }
        return true;
    }
};