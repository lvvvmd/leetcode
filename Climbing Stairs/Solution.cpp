class Solution {
public:
    int climbStairs(int n) {
        int last1 = 1, last2 = 2, now = 3;
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else{
        for(int i = 3;i<=n;i++){
            now = last1 + last2;
            last1 = last2;
            last2 = now;
        }
            return now;
        }
    }
};
