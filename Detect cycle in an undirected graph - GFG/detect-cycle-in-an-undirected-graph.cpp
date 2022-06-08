// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
         
         vector<int> visited(V+1,0);
        //  visited[adj[0]] = 1;;
         
         for(int i = 0; i < V; i++){
             
             if(visited[i] == 0){
                if( bfs(i,adj,visited))
                return true;
             }
         }
       return false; 
    }
    
    
    bool bfs(int i,vector<int> adj[],vector<int> &visited){
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i] = 1;
        while(!q.empty()){
            
            
            pair<int,int> p = q.front();
            
            int x = p.first;
            int y = p.second;
            q.pop();
            for(auto a : adj[x]){
                if(!visited[a]){
                    q.push({a,x});
                    visited[a] = 1;
                }
                else{
                    if(y != a)
                    return  true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends