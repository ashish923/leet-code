class NumMatrix {
public:
    int n ,m; 
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int  m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m,vector<int>(n,0));
         int s = 0;
        for(int i=0; i<n;i++){
              dp[0][i] = s+ matrix[0][i]; 
            s += matrix[0][i]; 
        }
        s = 0;
        for(int i=0; i<m;i++){
              dp[i][0] = s+ matrix[i][0]; 
            s += matrix[i][0]; 
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int start_i = row1,
            start_j = col1,
            end_i = row2,
            end_j = col2;
        if(start_i==0&&start_j!=0){
            return dp[end_i][end_j] - dp[end_i][start_j-1];
        }
        else if(start_i!=0&&start_j==0){
            return dp[end_i][end_j] - dp[start_i-1][end_j];
        }
        else if(start_i==0&&start_j==0){
            return dp[end_i][end_j];
        }
        else{
            return dp[end_i][end_j] - dp[start_i-1][end_j] -dp[end_i][start_j-1] +                      dp[start_i-1][start_j-1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */