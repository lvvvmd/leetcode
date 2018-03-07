class Solution {
public:
   int getMoneyAmount(int n) {
		vector<vector<int> > dp;
	for (int i = 0; i < n + 1;i++)
	{
		vector<int> row;
		for (int j = 0; j < n + 1;j++)
		{
			row.push_back(0);
		}
		dp.push_back(row);
	}

	for (int i = n; i > 0;i--)
	{
		for (int j = 1; j <= n;j++)
		{
			if (i >= j)
				dp[i][j] = 0;
			else if (j == i + 1)
				dp[i][j] = i;
			else{
				int minn = INT_MAX;
				for (int m = i; m < j;m++)
				{
					int tmp1 = dp[i][m - 1] + m;
					int tmp2 = m + dp[m + 1][j];
					if (max(tmp1, tmp2) < minn)
						minn = max(tmp1, tmp2);
				}
				if (minn > dp[i][j-1] + j)
				{
					minn = dp[i][j - 1] + j;
				}

				dp[i][j] = minn;

			}
		}
	}
	return dp[1][n];
}
};
