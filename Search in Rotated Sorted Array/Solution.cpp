class Solution {
public:
    int search2(vector<int>& nums, int target, int left0, int right0){
        if(left0 == right0)
            return -1;
        else if(right0 == left0+1){
            if(nums[left0] == target)
                return left0;
            else
                return -1;
        }
        else{
            int left = left0, right = right0-1;
            if(nums[left] < nums[right]){
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(nums[mid] == target)
                        return mid;
                    else if(nums[mid] < target)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                return -1;
            }
            else{
                int mid = (left + right) / 2;
                if(mid == left){
                    if(nums[left] == target)
                        return left;
                    else if(nums[right] == target)
                        return right;
                    else
                        return -1;
                    
                    
                }
                if(nums[mid] >= nums[left]){
                    if(nums[mid] > target && nums[left] <= target){
                        return search2(nums, target, left, mid);
                    }
                    else
                        return search2(nums, target, mid, right0);
                }
                else{
                    if(nums[mid] <= target && nums[right] >= target)
                        return search2(nums, target, mid, right0);
                    else
                        return search2(nums, target, left, mid);
                }
            }
            
        }
        
        
        
        
    }
    
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        else{
            int left = 0, right = nums.size();
            return search2(nums, target, left, right);
            
        }
    }
};
