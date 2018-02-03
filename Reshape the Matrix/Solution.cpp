class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int orir = nums.size();
        int oric = nums[0].size();
        if(orir * oric != c * r)
            return nums;
        int row = 0, col = 0;
        vector<vector<int>> rst;
        for(int i = 0;i<r;i++){
            vector<int> onerow;
            for(int j = 0;j < c;j++){
                onerow.push_back(nums[row][col]);
                col++;
                if(col == oric)
                {
                    col = 0;
                    row++;
                }
            }
            
            rst.push_back(onerow);
        }
        return rst;
        
    }
};
