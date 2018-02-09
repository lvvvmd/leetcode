class Solution {
public:
    vector<int> Trees;
    int numTrees(int n) {
        if(n < Trees.size() && Trees[n]!= 0) return Trees[n];\
        else if(n >= Trees.size()){
            for(int i = Trees.size();i<=n;i++)
                Trees.push_back(0);
        }
        if(n==0){
            Trees[n] = 1;
            return 1;
        }
        if(n==1){
            Trees[n] = 1;
            return 1;
        }
        int rst = 0;
        for(int i = 0;i<n;i++){
            rst += numTrees(i) * numTrees(n-1-i);
        }
        Trees[n] = rst;
        return rst;
    }
};
