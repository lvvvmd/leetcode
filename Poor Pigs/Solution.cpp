class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)
            return 0;
        else 
        return ceil(log(buckets) / (log(minutesToTest / minutesToDie + 1)));
    }
};
