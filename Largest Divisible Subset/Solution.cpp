class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
      if(nums.size()<=1)
          return nums;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> dp;
	for (int i = 0; i < n; i++){
		vector<int> tmp;
		dp.push_back(tmp);
	}
	dp[0].push_back(nums[0]);
	for (int i = 1; i < n; i++){
		int tmp = -1, tmpmax = 0;
		for (int j = i - 1; j >= 0; j--){
			if (nums[i] % nums[j] == 0 && dp[j].size()>tmpmax)
			{
				tmp = j;
				tmpmax = dp[j].size();
			}
		}
		if (tmp == -1){
			dp[i].push_back(nums[i]);
		}
		else{
			dp[i] = dp[tmp];
			dp[i].push_back(nums[i]);
		}
	}
	int maxcount = 0, maxindex = -1;
	for (int i = 0; i < n; i++){
		if (dp[i].size() > maxcount){
			maxcount = dp[i].size();
			maxindex = i;
		}
	}

	return dp[maxindex];
}
};
