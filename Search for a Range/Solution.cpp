class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rstL = -1, rstR = -1;
        int left = 0, right = nums.size() - 1;
        //find left
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[right] < target || nums[left] > target)
                break;
            if(target == nums[mid]){
                rstL = mid;
                right = mid - 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        left = 0, right = nums.size() - 1;
        //find left
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[right] < target || nums[left] > target)
                break;
            if(target == nums[mid]){
                rstR = mid;
                left = mid + 1;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        vector<int> rst;
        rst.push_back(rstL);
        rst.push_back(rstR);
        return rst;
        
    }
};
