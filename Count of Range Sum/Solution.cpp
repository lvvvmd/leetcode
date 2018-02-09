class Solution {
public:
   int countRangeSum(vector<int>& nums, int lower, int upper) {
	if (nums.size() == 0)
		return 0;
	int rst = 0;
	long long sum = 0;
	multiset<long long> sumset;
	for (int j = 0; j < nums.size(); j++){
		sum += nums[j];
        if(sum >= lower && sum <= upper)
            rst++;
        if(lower!=upper){
        auto m = sumset.lower_bound(sum - upper), n = sumset.upper_bound(sum - lower) ;
        rst += distance(m, n);
        }
        else{
            rst += sumset.count(sum - upper);
        }
		    
		sumset.insert(sum);
	}
    return rst;
    }
};
