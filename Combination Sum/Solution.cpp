class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rst;
        if(target < 0)
            return rst;
        else if(target == 0){
            vector<int> tmp;
            rst.push_back(tmp);
            return rst;
        }
        else{
            for(int i = 0;i<candidates.size();i++){
                vector<vector<int>> tmp = combinationSum(candidates, target - candidates[i]);
                
                for(int j = 0;j<tmp.size();j++){
                    tmp[j].push_back(candidates[i]);
                    rst.push_back(tmp[j]);
                }
                
            }
            
            for(int i = 0;i<rst.size();i++){
                sort(rst[i].begin(), rst[i].end());
            }
            sort(rst.begin(), rst.end());
            rst.erase(unique(rst.begin(), rst.end()), rst.end());
            return rst;
        }
    }
};
