class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums.size() < 3) return false;
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i-1] < nums[i] && nums[i+1] < nums[i]){
                auto min = min_element(nums.begin(), nums.begin()+i);
                for(int j = i+1;j<nums.size();j++){
                    if(*min < nums[j] && nums[j] < nums[i])
                        return true;
                }
            }
            
        }
        return false;
    }
};
