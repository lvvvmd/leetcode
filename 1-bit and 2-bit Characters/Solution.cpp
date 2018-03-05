class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1)
            return 1;
        while(bits.size() != 1){
            if(bits.size() == 0)
                return 0;
            if(bits[0] == 0)
                bits.erase(bits.begin());
            else{
                bits.erase(bits.begin());
                bits.erase(bits.begin());
            }
        }
        return 1;
    }
};
