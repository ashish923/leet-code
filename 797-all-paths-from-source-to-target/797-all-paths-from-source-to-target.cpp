class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> all;
        vector<int> vis(graph.size(),0);
        dfs(graph,0,all,vis,{});
        return all;
        
        
    }
    
    
    void dfs(vector<vector<int>>& graph,int i,vector<vector<int>> &all,vector<int> &vis,vector<int> v){
        v.push_back(i);
        
    if(i == graph.size() -1){
        all.push_back(v);
        return;
    }

        vis[i] = 1;
        for(auto x : graph[i]){

             dfs(graph,x,all,vis,v);

        }
        
    
    }
};