class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       // nums.erase(nums.end());
        if(nums.size() == 0)
            return nums;
        int i = 0;
        while(i+1 < nums.size()){
            if(nums[i] != nums[i+1]){
                nums.erase(nums.begin()+i);
                continue;
            }
            i++;
            
        }
        nums.erase(nums.end()-1);
        return nums;
    }
};
