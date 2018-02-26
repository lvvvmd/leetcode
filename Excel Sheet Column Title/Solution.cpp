class Solution {
public:
    string convertToTitle(int n) {
        n-=1;
        string rst;
        while(n/26!=0){
            string tmp = "A";
            tmp[0] += n % 26;
            rst = tmp + rst;
            
            
            n/=26;
            n-=1;
        }
        string tmp = "A";
        tmp[0] += n % 26;
        rst = tmp + rst;
        return rst;
    }
};
