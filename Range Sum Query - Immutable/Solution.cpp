class NumArray {
public:
    vector<int> m_nums;
    
    NumArray(vector<int> nums) {
        m_nums = nums;
    }
    
    int sumRange(int i, int j) {
        if(i==j)
            return m_nums[i];
        else{
            int count = 0;
            for(int m = i;m<=j;m++){
                count+=m_nums[m];
            }
        return count;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
