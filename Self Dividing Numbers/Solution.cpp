class Solution {
public:
    bool IsSelfDividing(int num){
        int ori = num;
        while(num!=0){
            int t = num%10;
            if(t == 0)
                return false;
            if(ori % t !=0)
                return false;
            
            num /=10;
        }
        
        return true;
        
        
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left;i<=right;i++){
            if(IsSelfDividing(i))
                result.push_back(i);
            
        }
        return result;
    }
};
