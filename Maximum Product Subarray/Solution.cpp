class Solution {
public:
    int allProduct(vector<int>& nums, int from, int to){
        int rst = 1;
        for(int i = from;i<to;i++){
            rst *= nums[i];
        }
        return rst;
    }
    
    void getNegative(vector<int>& nums, int& negcount, int& first, int& end){
        negcount = 0;
        for(auto i = nums.begin();i<nums.end();i++){
            if(*i < 0){
                if(negcount == 0)
                    first = i-nums.begin();
                negcount++;
                end = i-nums.begin();
            }
        }
        
    }
    
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else{
            auto zero = find(nums.begin(), nums.end(), 0);
            if(zero != nums.end()){
                vector<int> left, right;
                for(auto i = nums.begin();i<zero;i++){
                    left.push_back(*i);

                }
                for(auto i = zero+1;i<nums.end();i++){
                    right.push_back(*i);
                }
                return max(0, max(maxProduct(left), maxProduct(right)));
            }
            else{
                int negcount, first, end;
                getNegative(nums, negcount, first, end);
                if(negcount % 2 == 0){
                    return allProduct(nums, 0, nums.size());
                    
                }
                else{
                    return max(max(allProduct(nums, 0, first), allProduct(nums, first + 1 , nums.size())), max(allProduct(nums, 0, end), allProduct(nums, end + 1 , nums.size())));
                }
                
            }
        }
    }
};
