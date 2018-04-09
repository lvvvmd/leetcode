class Solution {
public:
    
bool canSplit(int target, vector<int>& nums, int m){
	int count = 0, sum = 0;
	for (int i = 0; i < nums.size(); i++){
		sum += nums[i];
		if (sum > target){
			sum = nums[i];
			count++;
			if (count >= m)
				return false;
		}
	}
	return true;

}


int splitArray(vector<int>& nums, int m) {
	long long sum = 0, max = -1;
	for (auto i = nums.begin(); i != nums.end(); i++){
		sum += *i;
		if (max < *i)
			max = *i;
	}
	long long l = max, r = sum;

	
	while (l <= r){
		long long mid = (l + r) / 2;
		if (canSplit(mid, nums, m))
			r = mid - 1;
		else
			l = mid + 1;

	}
	return l;
}

};
