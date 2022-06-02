class Solution {
public:
    int count = 0;
    int closedIsland(vector<vector<int>>& grid) {
        
       int n = grid.size();
        
        int m = grid[0].size();
        
        if(n<=2) return 0;
        int c = 0;
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0){
                    dfs(grid,0,i,n,m);
                    
                }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                    dfs(grid,i,0,n,m);
               
                }
        }
        for(int i=0; i<n; i++){
            if(grid[i][m-1] == 0){
                    dfs(grid,i,m-1,n,m);
                  
                }
        }
        for(int i=0; i<n; i++){
            
            if(grid[n-1][i] == 0){
                    dfs(grid,n-1,i,n,m);
                   
                }
        }
       
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[i].size()-1; j++){
                if(grid[i][j] == 0){
                    dfs(grid,i,j,n,m);
                    c++;
                }
                
            }
        }
        
        return c;
        
    }
    
    void dfs(vector<vector<int>> &grid,int i,int j,int n,int m){
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 1) return;
        
        
        grid[i][j] = 1;
        dfs(grid, i - 1, j , n , m);
        dfs(grid, i + 1, j , n , m);
        dfs(grid, i, j - 1 , n , m);
        dfs(grid, i, j + 1 , n , m);
    }
};