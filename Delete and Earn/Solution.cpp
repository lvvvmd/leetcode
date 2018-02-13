class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
		vector<int> num(10001, 0);
	for (int i : nums)
		num[i]++;
	vector<int> dp(10002, 0);
	dp[0] = 0;
	dp[1] = num[1] * 1;
	for (int i = 2; i < 10001; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + num[i] * i);
	}
	return dp[10000];
}
};
