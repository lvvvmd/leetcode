class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num-1;
        while(left <= right){
            long long mid =0;
            mid = (left+right) /2;
            long long mid2 = mid*mid;
            if(mid2 == num)
                return 1;
            else if(mid2 > num){
                right = mid -1;
            }
            else
                left = mid+1;
        }
        if(left*left == num)
            return 1;
        return 0;
    }
};
