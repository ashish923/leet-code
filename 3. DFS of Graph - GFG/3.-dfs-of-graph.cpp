// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> vc;
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      
      vector<int> visited(V,0);
      for(int i =0; i<V; i++){
          
          if(visited[i] == 0){
              dfs(adj,visited,i,V);
          }
          
      }
      
      return vc;

    }
    
    
    void dfs(vector<int> adj[],vector<int> &visited,int i,int n){
        
        
        visited[i] = 1;
        vc.push_back(i);
        // cout<<i<<" ";
        for(auto x : adj[i]){
            if(visited[x] == 1) continue;
            dfs(adj,visited,x,n);
        }
        
        return;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends