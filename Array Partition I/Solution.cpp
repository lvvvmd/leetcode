class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int rst = 0;
        sort(nums.begin(), nums.end());
        for (vector<int>::iterator it = nums.begin(); it < nums.end(); it = it+2){
            rst += *it;
        }
        
        return rst;
    }
};
