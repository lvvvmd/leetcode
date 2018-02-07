class Solution {
public:
    vector<vector<int>> subsetsUniqueN(vector<int> nums, int N, vector<int>::iterator begin, vector<int>::iterator end) {
        vector<vector<int>> rst;
        if(N > end - begin)
            return rst;
        else if(N == 0 || begin == end){
            vector<int> subset;
            rst.push_back(subset);
            return rst;
        }
        else{
            for(;begin < end ; begin ++){
                vector<vector<int>> remain = subsetsUniqueN(nums, N-1, begin +1, end);
                for(auto i = remain.begin();i < remain.end();i++){
                    (*i).push_back(*begin);
                    rst.push_back(*i);
                }
            }
        }
        return rst;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        for(int i = 0;i <= nums.size(); i++){
            vector<vector<int>> remain = subsetsUniqueN(nums, i, nums.begin(), nums.end());
             for(auto j = remain.begin();j < remain.end();j++){
                    rst.push_back(*j);
            }
        }
        return rst;
    }
};
