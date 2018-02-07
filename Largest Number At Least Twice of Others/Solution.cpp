class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1, index = -1;
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        
        for(int i = 0;i<nums.size();i++){
            if(i != index){
                if(max < nums[i] * 2)
                    return -1;
                
                
            }
        }
        return index;
    }
};
