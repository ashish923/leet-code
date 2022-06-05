class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        q.push({0,0});
        int c = 0;
        while(!q.empty()){
            
            int size = q.size();
            c++;
            while(size--){
             pair<int,int> p = q.front();   
                int x = p.first;
                int y = p.second;
                if(x == n-1 && y == m-1) return c;
                q.pop();
               for(int i = x - 1 ; i <= x + 1 ; i++){
                   
                   for(int j = y - 1 ; j <= y + 1 ; j++){
                       if(check(i,j,n,m) && grid[i][j] == 0){
                           grid[i][j] = 1;
                           q.push({i,j});
                       }
                   }
               }
                
            }    
        }
        
        return -1;
    }
    
    bool check(int i,int j ,int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        return 1;
    }
};