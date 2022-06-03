class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        
        
        int n = grid1.size();
        int m = grid1[0].size();
        int c=0,f=0;
        for(int i=0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(grid2[i][j] == 1 && grid1[i][j] == 1){
                        dfs(grid1,grid2,i,j,n,m,f);
                        if(f == 0)
                            c++;
                        f=0;
                    }
                }
            
        }
        return c;
        
    }
    
    void dfs(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int i,int j,int n,int m,int &f){
        
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j] == 0) return;
        
        if(grid1[i][j] == 0) f = 1;
        grid2[i][j] = 0;
        dfs(grid1,grid2, i - 1, j , n , m,f);
        dfs(grid1,grid2, i + 1, j , n , m,f);
        dfs(grid1,grid2, i, j - 1 , n , m,f);
        dfs(grid1,grid2, i, j + 1 , n , m,f);
    }
};