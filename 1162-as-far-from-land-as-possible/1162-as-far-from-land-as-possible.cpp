class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        // vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        // if(q.empty()) return -1;
        
       int c = 0; 
        
        while(!q.empty()){
            
            int size = q.size();
            c++;
            while(size--){
            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;
                // cout<<x<<" "<<y<<" \n";
            q.pop();
                for(auto a : dir){
                   int  xx = x + a[0];
                    int yy = y + a[1];
                    if(check(grid,xx,yy) && grid[xx][yy] == 0){
                        grid[xx][yy] = 1;
                        q.push({xx,yy});
                    }
                }  
            }
            // cout<<"\n";
        }
        
       if(c==1) return -1;
        return c-1;
        
        
    }
    
    bool check(vector<vector<int>>& grid,int x, int y){
        
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
            return 0;
        }
        return 1;
    }
};