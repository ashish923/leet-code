class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& arr) {
        queue<int> q;
	   vector<vector<int>> adj(V);
        for(auto &i: arr) {
            adj[i[0]].push_back(i[1]);
        }
        
        vector<int> indegree(V,0);
	   for(int i=0; i<V; i++){
	       for(auto a : adj[i])
	            indegree[a]++;
	   }
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	   
	   vector<int> res;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       res.push_back(node);
	       for(auto a : adj[node]){
	           indegree[a]--;
	           if(indegree[a] == 0)
	           q.push(a);
	       }
	       
	   }
        for(int i=0; i<V; i++){
            if(indegree[i] > 0)
                return {};
        }
        reverse(res.begin(),res.end());
	   return res; 
    }
};