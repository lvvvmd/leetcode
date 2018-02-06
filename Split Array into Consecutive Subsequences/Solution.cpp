class Solution {
public:
    bool isPossible(vector<int>& nums) {
vector<int> count;
	for (auto i = nums.begin(); i<nums.end(); i++){
		int countc = 0;
		while (1){
			countc++;
			if (i + 1 == nums.end() || *i != *(i + 1))
				break;
			i++;
		}
		count.push_back(countc);
	}

	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	//cout << nums.begin() - nums.end() << endl;

	while (1){
		if (nums.size() == 0)
			return true;
		if (nums.size() < 3)
			return false;
		//else 
		int i = nums.size() - 1;
		int seqnum = 0;
		for (;;)
		{
			seqnum++;
			if (i == 0 || nums[i] - nums[i - 1] > 1 || count[i] > count[i - 1]){//到终点了
				if (seqnum < 3)
					return false;
				else{
					//删掉这个子序列
					for (int j = nums.size() - 1; j >= i; j--){
						count[j]--;
						//cout << nums[j] << ' ';
						if (count[j] == 0){
							count.erase(j + count.begin());
							nums.erase(j + nums.begin());
						}

					}


				}
				break;
			}
			else{
				i--;
			}
		}
		

	}
	return true;
    }
};
