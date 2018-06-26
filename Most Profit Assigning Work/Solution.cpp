class Solution {
public:
    struct work{
        int diff;
        int prof;
        
    };
    static bool cmp(work &a, work &b){
        if(a.diff > b.diff)
            return 0;
        else
            return 1;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<work> w;
        for(int i =0;i< difficulty.size();i++){
            work tmp;
            tmp.diff = difficulty[i];
            tmp.prof = profit[i];
            w.push_back(tmp);
        }
        sort(w.begin(), w.end(), cmp);

        sort(worker.begin(), worker.end());
        int rst = 0;
        int j = 0, maxp = -1, maxi = -1;
        for(int i = 0;i<worker.size();i++){
            
            while(j<w.size()){
                if(w[j].diff > worker[i]){
                    break;
                }
                else{
                    if(w[j].prof > maxp){
                        maxp = w[j].prof;
                        maxi = j;
                        
                    }
                    j++;
                }
                
                
            }
            if(maxi != -1)
                rst += w[maxi].prof;
            
        }
        return rst;   
    }
};
