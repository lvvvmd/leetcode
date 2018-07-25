class NumMatrix {
public:
    vector<vector<int> > sum;
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if(m == 0)
            return ;
        int n = matrix[0].size();
        vector<vector<int> > sum2(m + 1,vector<int>(n + 1,0));
        sum = sum2;
        for(int i = 0;i < m+1; i++){
            for(int j = 0; j < n+1;j++){
                if(i != 0 && j != 0){
                    sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};
