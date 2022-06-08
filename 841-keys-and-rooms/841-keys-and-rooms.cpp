class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        

        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;
        while(!q.empty()){
            
            int z = q.front();
            q.pop();
            // cout<<z<<" ";
            vis[z] = 1;
            for(auto x : rooms[z]){
                if(!vis[x]) 
                    q.push(x);

            }
        }
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
             // cout<<i;
                return false;
            }
        }
        
        return true;
        
    }
};