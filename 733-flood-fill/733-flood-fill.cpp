class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
          
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int oldcolor = image[sr][sc];
       vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
         if(image[sr][sc]==newColor)   
            return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        while(!q.empty()){
            
            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            for(auto a : dir){
                
                int xx = x + a[0];
                int yy = y + a[1];
                // cout<<a[0]<<" "<<a[1]<<" "<<x<<" "<<y<<" \n";
                if(check(xx,yy,n,m) && image[xx][yy] == oldcolor){
                    // cout<<xx<<yy<<image[xx][yy];
                    q.push({xx,yy});
                    image[xx][yy] = newColor;
                }
            }
            
        }
        return image;
    
    }
    bool check(int i,int j,int n,int m)
    {
        if(i>=n || j>=m || i<0 || j<0)
            return 0;
        else
            return 1;
        
    }
};