class Solution {
public:
    bool isNondec(vector<int>& nums){
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1])
                return 0;
        }
        return 1;
        
    }
    
    
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        bool flag = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] >nums[i+1]){
                if(flag == true)
                    return false;
                else{
                    flag = true;
                    vector<int> nums1, nums2;
                    nums1 = nums2 = nums;
                    nums1.erase(nums1.begin()+i);
                    nums2.erase(nums2.begin()+1+i);
                    if(isNondec(nums1) || isNondec(nums2)){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return 1;
    }
};
