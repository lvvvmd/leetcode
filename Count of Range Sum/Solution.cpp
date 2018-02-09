class Solution {
public:
   int countRangeSum(vector<int>& nums, int lower, int upper) {
	if (nums.size() == 0)
		return 0;
	int rst = 0;
	long long sum = 0;
	for (int j = 0; j < nums.size(); j++){
		sum = 0;
		for (int i = j; i < nums.size(); i++){
			sum += nums[i];
			if (sum >= lower && sum <= upper)
				rst++;
		}
	}
	//nums.erase(nums.begin());
	//rst += countRangeSum(nums, lower, upper);
	return rst;
    }
};
