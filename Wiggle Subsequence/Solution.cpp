#include <math>

class Solution {
public:
    int sign(int a){
        if(a == 0)
            return 0;
        else
            return a / abs(a);
    }
    
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size() == 0 || nums.size() == 1) 
            return nums.size();
        
        vector<int> rst;
        
        for(auto i = nums.begin();i != nums.end();i++){
            if(i == nums.begin() || (i == nums.begin() + 1) && *i != *(i-1)){
                rst.push_back(*i);
            }
            if(*i == *(rst.end()-1))
                continue;
            else if(*i > *(rst.end()-1)){
                if(rst.size() == 0 || rst.size() == 1)
                    rst.push_back(*i);
                else if(*(rst.end()-2) > *(rst.end()-1)){
                    rst.push_back(*i);
                }
                else
                    *(rst.end()-1) = *i;
            }
            else{
                if(rst.size() == 0 || rst.size() == 1)
                    rst.push_back(*i);
                else if(*(rst.end()-2) < *(rst.end()-1)){
                    rst.push_back(*i);
                }
                else{
                    *(rst.end()-1) = *i;
                }
            }
        }

        return rst.size();
        
        return wiggleMaxLength2(diff) + 1;
                           
    }
};
