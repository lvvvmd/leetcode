class Solution {
public:
    int findComplement(int num) {
        int rst = 0, count = 1;
        while(num!=0){
            rst += count*(1-(num%2));
            num /= 2;
            count *= 2;
        }
        return rst;
    }
};
