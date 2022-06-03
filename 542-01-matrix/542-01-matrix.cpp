class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0)
                    q.push({i,j});
            }
        }
        
        int c = 0;
        while(!q.empty()){
            
            int size = q.size();
              c++;
            while(size--){
                
                pair<int,int> p = q.front();
                int x = p.first;
                int y= p.second;
                q.pop();
                // cout<<x<<" "<<y<<" \n\n";
                for(auto a : dir){
                    int xx = x + a[0];
                    int yy = y + a[1];
                     // cout<<xx<<" "<<yy<<" \n";
                    if(check(xx,yy,n,m) && mat[xx][yy] == 1){
                        // cout<<"h";
                        mat[xx][yy] = (-1)*(c);
                        q.push({xx,yy});
                    }
                }
                
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[i][j] *= (-1);
            }
        }
        

        return mat;
        
    }
    
    bool check(int x, int y,int n,int m){
        if(x<0 || x >= n || y < 0 || y >= m)
            return 0;
        return 1;
    }
};