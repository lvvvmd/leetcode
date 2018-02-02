class Solution {
public:
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size() - 1;i++){
            //行的循环
            for(int j = 0; j <matrix[i].size()-1;j++){
                //列的循环
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }

            
            
        }
        return true;
    }
};
