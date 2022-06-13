class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n= graph.size();
        vector<int> vis(n,-1);
        
        
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
               
                if(!bipartite_dfs(graph,vis,i)) return false;
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
            else if(vis[a] == vis[i])
                return false;
        }
        return true;
    }

    bool check_bipartite(vector<vector<int>>& graph,vector<int> &vis,int i){
        queue<int> q;
         vis[i] = 1;
        q.push(i);
        while(!q.empty()){
           
            int z = q.front();
            q.pop();
            for(auto a : graph[z]){
                 if(vis[a] == -1) { 
                  
                    q.push(a);
                    vis[a] = 1 - vis[z]; 
                }
                else if(vis[a] == vis[z]) 
                { 

                    return false;
                }
            }   
        }
        
        return true;
    }
};