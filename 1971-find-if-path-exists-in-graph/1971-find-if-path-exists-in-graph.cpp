class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
       vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        queue<int> q;
        q.push(source);
        vector<int> visited(n);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == destination) return true;
            
            for(auto a : adj[node]){
                if(!visited[a]){
                    visited[a] = 1;
                    q.push(a);
                }
            }
        }
        
        return 0;
        
    }
};