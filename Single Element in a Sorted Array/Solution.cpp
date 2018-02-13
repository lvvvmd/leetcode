class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size();){
            if(i == nums.size()-1)
                return nums[i];
            else if(nums[i] != nums[i+1])
                return nums[i];
            else if(nums[i] == nums[i+1])
                
                i += 2;
        }
    }
};
