class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1;i<=n;i++)
            nums.push_back(i);
        for(int i = 0;i<k-1;i++)
            next_permutation(nums.begin(), nums.end());
        string rst;
        for(int i = 0;i<n;i++)
            rst += nums[i] + '0';
        return rst;
        
    }
};
