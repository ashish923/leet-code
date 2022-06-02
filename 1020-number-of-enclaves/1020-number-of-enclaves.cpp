class Solution {
public:
    int count = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int c =0;
        if(n<=2 || m<=2) return 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 cout<<grid[i][j]<<" ";
//             }
//             cout<<"\n";
//         }
        
       
        
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1){
                    dfs(grid,0,i,n,m);
                    
                }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                    dfs(grid,i,0,n,m);
               
                }
        }
        for(int i=0; i<n; i++){
            if(grid[i][m-1] == 1){
                    dfs(grid,i,m-1,n,m);
                  
                }
        }
        for(int i=0; i<m; i++){
            
            if(grid[n-1][i] == 1){
                    dfs(grid,n-1,i,n,m);
                   
                }
        }
        // cout<<"********************************8\n";
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        count =0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                c += grid[i][j];
            }
        }
     return c;   
    }
    
     void dfs(vector<vector<int>> &grid,int i,int j,int n,int m){
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0) return;
        
        
        grid[i][j] =0;
        dfs(grid, i - 1, j , n , m);
        dfs(grid, i + 1, j , n , m);
        dfs(grid, i, j - 1 , n , m);
        dfs(grid, i, j + 1 , n , m);
    }
    
    
};