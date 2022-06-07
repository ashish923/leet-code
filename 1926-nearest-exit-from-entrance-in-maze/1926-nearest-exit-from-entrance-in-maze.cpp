class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
         int k = INT_MAX;
        int n = maze.size();
        int m = maze[0].size();
        int i = entrance[0];
        int j = entrance[1];
        int c =0;
        
        vector<vector<int>> dir = {
            {0,1},{1,0},{-1,0},{0,-1}
        };
        
        
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        // int c =0;
        maze[i][j] = '+';
        
        while(!q.empty()){
            
            int size = q.size();
            c++;
            while(size--){
                
                pair<int,int> p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();
                for(auto a : dir){
                    int xx = x + a[0];
                    int yy = y + a[1]; 
                    
                   if((xx >=0 && xx < n && yy >= 0 && yy <m) && maze[xx][yy] == '.'){ 
                   
                       if(xx ==0 || xx == n-1 || yy == 0 || yy == m - 1) return c;
                       
                        q.push({xx,yy});
                        maze[xx][yy] = '+';
                    

                     }
                
                 }
            }
        }
        return -1;
        
    }
};