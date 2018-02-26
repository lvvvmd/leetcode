class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rst = 0;
        if(prices.size() <= 1)
            return 0;
        
        int currentmin = 99999999, currentmax = -1;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] > currentmax){
                currentmax = prices[i];
            }
            if(prices[i] < currentmin){
                currentmin = prices[i];
                currentmax = prices[i];
            }
            rst = rst < (currentmax - currentmin) ? (currentmax - currentmin):rst;
            
        }
        return rst;
    }
};
