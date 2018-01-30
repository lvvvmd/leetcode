class Solution {
public:
    int hammingDistance(int x, int y) {
        int z, count = 0;
        z = x^y;
        while(z!=0){
            if(z%2 == 1)
                count ++;
            
            z /= 2;
        }
        return count;
    }
};
